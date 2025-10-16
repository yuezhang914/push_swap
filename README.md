
# push_swap 

A practice project that sorts an integer sequence using a limited set of stack operations (from the 42 curriculum).

---

## What this project is

`push_swap` is a program that sorts a sequence of integers while only using a restricted set of stack operations (`sa`/`sb`/`ss`/`pa`/`pb`/`ra`/`rb`/`rr`/`rra`/`rrb`/`rrr`). The goal is to output an optimal or near-optimal sequence of operations that results in the input stack (A) being sorted in ascending order, with all elements ending up back in stack A. The program accepts either individual command-line arguments for each number or a single quoted string containing space-separated numbers, and prints the operations line by line to standard output (for use with a `checker` or for manual verification).

---

## What I did

I implemented and integrated the entire `push_swap` project from scratch, including:

* Input parsing and strict validation: safely parsing both separate command-line arguments and a single quoted string, detecting non-numeric input, overflow, duplicates, and reporting errors appropriately.
* Core stack & node structures: implemented a doubly-linked list node type (`t_node`) with constructors, insert/delete, length, and other low-level operations used by the stack commands.
* Full set of stack operations: implemented all required operations (`sa`/`sb`/`ss`, `pa`/`pb`, `ra`/`rb`/`rr`, `rra`/`rrb`/`rrr`) and print the corresponding operation name when each is invoked (so an external `checker` can validate the result).
* Sorting algorithm: implemented a strategy based on “prepare nodes / cost calculation / cheapest move”:

  * For small sizes (e.g. 2, 3, 5) use specialized fast strategies (e.g. `sort_three`).
  * For larger sizes, move part of the elements from A to B (`move_a_to_b`), find for each node in B its target insertion point in A (`find_b_target_in_a` / `set_target_*`), compute move costs, and choose the “cheapest” node to move in order to reduce total operations.
  * Finally, move elements from B back into A in the correct order (`to_the_top` + `pa`), adjust indices, and rotate the smallest element to the top to finish the sorted stack.
* Helpers & robustness: implemented index preparation (`prepare_index`), cost calculation and cheapest selection (`prepare_cheapest` / `find_cheapest`), error reporting, and resource management.
* Integrated `libft`: included my custom `libft` in the repository and wired it into the build, reusing string/memory/printing utilities.
* Makefile: wrote a `Makefile` supporting standard targets (`make`, `make clean`, `make fclean`, `make re`) and an optional `push_swap_bonus` target.

---

## Completed features (itemized)

### Input & validation

* Support two input styles: each number as a separate command-line argument, or a single quoted string containing space-separated numbers.
* Validation includes: legal integers (avoid overflow), no non-digit characters, no duplicate values. On error the program returns a non-zero exit status and prints an error message.

### Core operations

* Implemented and correctly output the following stack operations (behavior matches the project spec):

  * Swap: `sa`, `sb`, `ss`
  * Push/pop: `pa`, `pb`
  * Rotate (up / left shift): `ra`, `rb`, `rr`
  * Reverse rotate (down / right shift): `rra`, `rrb`, `rrr`

### Sorting strategy

* Use a dedicated strategy for small counts (2–3) with `sort_three` to finish quickly.
* For larger inputs use this overall flow:

  1. Preprocess and assign an index to each node in A (`prepare_index`).
  2. Move a subset of elements from A to B (`move_a_to_b`), computing for each B node its target position in A (`set_target_*`) while moving.
  3. Compute the total cost (rotate/reverse-rotate steps) for each candidate move and mark the “cheapest” node (`prepare_cheapest`).
  4. Execute the cheapest move: rotate both A and B so the candidate nodes reach the top (`to_the_top`), then `pb`/`pa` as needed to move elements from B back into A in order.
  5. Finally, normalize A by rotating the smallest element to the top to yield a sorted ascending stack.
* The algorithm focuses on “cost estimation + pick the cheapest move” — a greedy approach that is effective in practice to reduce total moves.

### Tools & build

* `Makefile`: builds `push_swap` (default) and `push_swap_bonus` (if desired), and integrates the `libft` build steps.
* Bundled `libft`: reuses custom string, memory, and output helpers to avoid external dependencies.

---

## Project structure (directory overview)

```
pushswap/                        # repository root
├─ includes/                     # public headers (push_swap.h)
├─ src/                          # source code
│   ├─ main.c                    # program entry, argument dispatch and main flow
│   ├─ init.c                    # initialize stacks, build linked list from args
│   ├─ validate.c                # argument & duplicate detection
│   ├─ token_safe.c              # safe integer parsing (no overflow, no invalid chars)
│   ├─ utils.c                   # stack utilities and helpers (find_cheapest, stack_len, ...)
│   ├─ cmd_swap.c                # sa/sb/ss implementations
│   ├─ cmd_push.c                # pa/pb implementations
│   ├─ cmd_rotate.c              # ra/rb/rr implementations
│   ├─ cmd_rev_rotate.c          # rra/rrb/rrr implementations
│   ├─ prepare_a.c / prepare_b.c # compute targets, costs, bring nodes to top, etc.
│   ├─ sort.c                    # high-level sorting logic (move_a_to_b, reinsertion, ...)
│   └─ error.c                   # error reporting and exit handling
├─ libft/                        # bundled custom libft (integrated into build)
├─ Makefile                      # build script (all / bonus / clean / fclean / re)
```

---

## Usage

### Build

From the repository root run:

```bash
# build
make
```

After building, the executable `push_swap` will be produced.

### Run

Pass a sequence of integers to the program — it prints the operations used to sort, one per line:

```bash
# each number as a separate argument
./push_swap 3 2 1 0

# or provide all numbers in a single quoted string
./push_swap "3 2 1 0"
```

Example output (illustrative):

```
pb
sa
pa
```

Those outputs can be fed to an external `checker` program to validate the final sorted state and count the total operations.

---

## Design & implementation notes (technical summary)

* Data structures: stacks are implemented as doubly-linked lists. Each node stores value, index, a target pointer, and fields used for cost calculation (`cost`, `cheapest`, `up_down`, etc.).
* Small-size optimization: for stacks of length ≤ 3 (or at another chosen threshold) use a minimal-step procedure to avoid unnecessary computation.
* Greedy cost estimation: for each node in B compute the total cost to insert it into A (including rotations on both stacks), mark the cheapest node and perform the combined rotations + push. This reduces the total number of operations in practice.
* Testability: strict input validation, clear error messages, and plain-text operation output make it easy to use with a `checker` or automated test scripts.


---

# push_swap 

一个用受限栈操作把整数序列排序的练习项目（来自 42 课程题目）。

---

## 项目是什么

`push_swap` 是一个把整数序列排序的程序，但只能使用一组受限的栈操作（`sa`/`sb`/`ss`/`pa`/`pb`/`ra`/`rb`/`rr`/`rra`/`rrb`/`rrr`）。目标是输出一个最优或接近最优的操作序列，使输入栈（A）按升序排列，最终所有元素回到栈 A。程序接收命令行参数或单个带空格的字符串作为输入数字，并把操作按行打印到标准输出（供 `checker` 或人工验证使用）。

---

## 我做了什么

我从零实现并集成了整个 `push_swap` 项目，包括：

* 输入解析与严格校验：安全地解析命令行参数与带空格的字符串形式，检测非数字、溢出、重复值等错误情况并妥善报错。
* 基本栈与节点结构：实现双向链表节点（`t_node`）构造、插入、删除、获取长度等基础操作，为各个栈指令提供数据结构支持。
* 完整的栈操作实现：实现了所有要求的操作函数（`sa`/`sb`/`ss`、`pa`/`pb`、`ra`/`rb`/`rr`、`rra`/`rrb`/`rrr`），并在调用处输出对应操作名称（供外部 checker 使用）。
* 排序算法：实现一种基于“准备节点 / 代价计算 / 最便宜的移动”策略的排序方法：
* 对小规模（比如 2、3、5）情况使用专门的快速排序策略（`sort_three` 等）。
* 对较大规模，通过把部分元素从 A 移到 B（`move_a_to_b`），为 B 中每个节点在 A 中找到目标插入点（`find_b_target_in_a` / `set_target_*`），计算移动代价并选择“cheapest”（最便宜）节点进行一次合并移动，以减少总操作数。
* 最后把 B 中元素按目标顺序移回 A（`to_the_top` + `pa`），调整索引并把最小元素放到顶端完成最终排序。
* 辅助工具与健壮性：实现索引预处理（`prepare_index`）、计算代价与选择最优移动（`prepare_cheapest` / `find_cheapest`）、错误输出与资源管理。
* 集成 `libft`：把自写的 `libft` 放进仓库并与编译流程集成，复用字符串、分配、打印等工具函数。
* Makefile：编写 `Makefile` 支持标准目标（`make`, `make clean`, `make fclean`, `make re`）以及 `push_swap_bonus` 可选目标。

---

## 已完成的功能

### 输入与校验

* 支持两种输入方式：每个数字作为单独命令行参数，或单个字符串参数内包含空格分隔的数字。
* 校验内容包括：是否为合法整数（防止溢出）、是否含非数字字符、是否有重复值（duplicate）、错误时返回非零并输出错误信息。

### 基础操作

* 实现并正确输出以下栈操作（行为与题目要求一致）：

  * 交换：`sa`, `sb`, `ss`
  * 推送/弹栈：`pa`, `pb`
  * 上旋/左移：`ra`, `rb`, `rr`
  * 逆旋/右移：`rra`, `rrb`, `rrr`

### 排序策略

* 针对小量元素（2~3）使用专用策略（`sort_three`）快速完成排序。
* 针对更大数据集，采用如下总体流程：

  1. 预处理并为 A 中每个节点分配索引（`prepare_index`）。
  2. 把一部分元素移动到 B（`move_a_to_b`），在移动过程中为 B 中元素计算在 A 中的目标插入位置（`set_target_*`）。
  3. 计算每个候选移动的总代价（旋转/逆旋步数），标注“cheapest”节点（`prepare_cheapest`）。
  4. 执行最“便宜”的移动：同时把 A 和 B 对应节点移动到栈顶（`to_the_top`），然后 `pb`/`pa` 进行操作，逐步把元素从 B 按顺序放回 A。
  5. 最后整理 A（把最小值置顶）以得到升序排列。
* 算法侧重通过“代价估算 + 选择最便宜的移动”来尽量减少总操作数，这是一种在实践中被证明有效的贪心式方案。

### 工具与构建

* Makefile：支持 `make`（构建 `push_swap`），以及 `make bonus`（构建 `push_swap_bonus`），并与 `libft` 的构建流程集成。
* 自带 `libft`：复用自写的字符串、内存和输出工具，减少外部依赖。

---

## 整体项目模块构成（目录说明）

```
pushswap/                        # 仓库根
├─ includes/                     # 公共头文件（push_swap.h）
├─ src/                          # 源代码
│   ├─ main.c                    # 程序入口、参数分发与主流程
│   ├─ init.c                    # 初始化栈、从参数构建链表节点
│   ├─ validate.c                # 参数与重复值检测
│   ├─ token_safe.c              # 安全解析数字（无溢出、无非法字符）
│   ├─ utils.c                   # 栈工具与辅助函数（find_cheapest、stack_len 等）
│   ├─ cmd_swap.c                # sa/sb/ss 实现
│   ├─ cmd_push.c                # pa/pb 实现
│   ├─ cmd_rotate.c              # ra/rb/rr 实现
│   ├─ cmd_rev_rotate.c          # rra/rrb/rrr 实现
│   ├─ prepare_a.c / prepare_b.c # 计算目标、代价、定位顶端等准备函数
│   ├─ sort.c                    # 高层排序逻辑（move_a_to_b、回插等）
│   └─ error.c                   # 错误输出与退出处理
├─ libft/                        # 自写的 libft（被集成与编译）
├─ Makefile                      # 构建脚本（all / bonus / clean / fclean / re）
```

---

## 使用说明

### 编译

在仓库根目录运行：

```bash
make


构建后会生成可执行文件 `push_swap`。

### 运行

把一系列整数传给程序，程序会把排序用到的操作每行一条输出：

```bash
# 每个数字作为单独参数
./push_swap 3 2 1 0

# 或者把所有数字放在一个引用字符串中
./push_swap "3 2 1 0"
```

输出示例（示意）：

```
pb
sa
pa
```

这些输出可以交给外部的 `checker` 程序验证最终是否已经排序，并统计操作总数。

---

## 设计与实现细节

* 数据结构：使用双向链表实现栈节点，节点结构包含值、索引、目标指针与用于计算的字段（如 `cost` / `cheapest` / `up_down` 等）。
* 小规模优化：当栈长度 <= 3（或其他临界值）时使用专用的最少步骤置换方案以减少不必要的计算。
* 贪心+代价估算：核心思想是对 B 中每个节点计算将其插入 A 的总代价（包括 A 和 B 的旋转步数），标记最便宜节点并执行对应的“联合旋转 + push”。这种方法在实践中可以显著降低操作数量。
* 可测试性：输入校验、错误报告、以及把每个操作以文本形式输出，便于组合 `checker` 或自动化脚本进行验证。

---
