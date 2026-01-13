# 🚀 XCPC - Algorithm Competition Archive

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)
![IDE](https://img.shields.io/badge/IDE-VS%20Code-007ACC?style=flat-square&logo=visual-studio-code)
![Status](https://img.shields.io/badge/status-active-success?style=flat-square)
![Repo Size](https://img.shields.io/github/repo-size/XUNRANA/XCPC?style=flat-square)

## 📖 简介 (Introduction)

> **Welcome to the world of algorithms!** 🌏

这里是 **[XUNRANA]** 的算法竞赛代码仓库。
本项目记录了我的算法刷题之路，包含了在各大 OJ (Online Judge) 上的解题代码、比赛复盘以及个人整理的算法模板。

主要包含 **C++** 实现的算法代码，面向 **ICPC/CCPC/Codeforces** 等算法竞赛。

## 📂 目录结构 (Directory Structure)

仓库目前按照 OJ 平台及比赛类型进行分类归档：

# 🚀 XCPC - 算法竞赛代码仓库

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B)
![IDE](https://img.shields.io/badge/IDE-VS%20Code-007ACC?style=flat-square&logo=visual-studio-code)
![Status](https://img.shields.io/badge/status-active-success?style=flat-square)

## 📖 项目简介

`XCPC` 是作者用于记录算法练习与比赛解题的仓库，主要保存来自 Codeforces、Atcoder、Luogu、HDU 等平台的题解代码与个人模板。仓库以平台/比赛/题目为单位分类，方便复盘与检索。

目标受众：算法学习者、竞赛选手、想看高质量题解的读者。

## 📂 目录说明

仓库按照平台与比赛归类，示例目录结构：

```text
XCPC/
├── 00 Codeforces/      # Codeforces 比赛代码 (Div.1 - Div.4)
├── 01 Atcoder/         # Atcoder 比赛代码
├── 02 Luogu/           # Luogu 题目与练习
├── 04 HDU/             # HDU 题目
├── 12 XCPC模板/        # 常用模板与工具代码
├── .vscode/            # 编辑器配置
└── README.md           # 项目说明
```

## 🔖 README 中应包含的信息（已改进）

- 项目简介与目录结构
- 如何运行示例代码与编译（Windows / Linux / WSL）
- 代码文件头注释规范（题目链接 / 标签 / 难度 / 状态）
- 统计与标签维护说明（`problems.csv` 或 `tags.json`）
- 如何贡献（提交规范、PR 流程、命名规则）

## ⚙️ 快速使用说明

在 Windows 下使用 VS Code 和 MinGW 编译单个 C++ 文件示例：

```bat
:: 在仓库中打开终端并运行（示例）
cd "00 Codeforces/1000 div2 01.22"
g++ -std=c++17 -O2 A.cpp -o A.exe
.\\A.exe
```

若在 Linux / WSL：

```bash
cd "00 Codeforces/1000 div2 01.22"
g++ -std=c++17 -O2 A.cpp -o A
./A
```

## 🧾 代码注释模板（建议）

在每个题目文件顶部加入统一注释，便于检索与统计，例如：

```cpp
// Problem: 1000A - Example Problem
// Link: https://codeforces.com/contest/1000/problem/A
// Difficulty: easy
// Tags: math, implementation
// Status: AC
```

将上述信息同步到问题数据库（`problems.csv` / `tags.json`），便于后续统计。

## 📊 统计与维护建议

- 使用 `problems.csv` 或 `tags.json` 存储题目信息（id, title, link, tags, difficulty, status）。
- 编写一个小脚本生成统计（题目数、按标签分布、AC 率等），并将其纳入 CI（可选）。

示例 `problems.csv` 列：

```
file,id,title,link,tags,difficulty,status
00 Codeforces/1000 div2 01.22/A.cpp,1000A,Example,https://...,math;greedy,easy,AC
```

## 🤝 如何贡献

贡献流程建议：

1. Fork 仓库并新建分支 `feature/<platform>-<contest>-<id>`。
2. 在对应目录添加代码文件，文件名请保持与题目编号/字母一致（示例：`1000A.cpp` 或 `A.cpp`）。
3. 在文件头添加注释模板并在 `problems.csv`（或 `tags.json`）中添加条目。
4. 提交 PR，描述改动与来源链接。

代码风格建议：

- 保持可读性，适当添加注释；竞赛模板可使用 `#include <bits/stdc++.h>`，但库/项目代码请避免全包含。

## 🧰 模板目录说明

`12 XCPC模板/` 中包含常用算法模板（图论、数据结构、字符串处理、数学工具等）。建议为每个模板添加：用途说明、复杂度、示例链接。

## 📎 自动化（可选）

- 建议添加 `scripts/`：包含统计脚本 `generate_stats.py`、批量编译脚本 `build_all.sh`。
- 可在 GitHub Actions 中添加工作流，自动运行统计并在 PR 检查编译错误。

## 📄 许可证

本仓库默认使用 MIT 许可证（如需更改，请添加 LICENSE 文件）。

