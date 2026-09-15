*This project has been created as part of the 42 curriculum by myazawa and yudakane.*

# 概要

`push_swap` は42カリキュラムのアルゴリズム系プロジェクトです。

このプロジェクトの目的は、2つのスタック `a` と `b`、そして限られた操作だけを使用して、スタック `a` に格納された整数を昇順に並べ替えることです。

プログラムには整数列を引数として渡します。

最初の状態では、すべての整数がスタック `a` に入り、スタック `b` は空です。

```text
Stack A                  Stack B

[ 3 ]                    [   ]
[ 1 ]                    [   ]
[ 5 ]                    [   ]
[ 2 ]                    [   ]
[ 4 ]                    [   ]
```

最終的には、スタック `a` が昇順になるようにします。

```text
Stack A                  Stack B

[ 1 ]                    [   ]
[ 2 ]                    [   ]
[ 3 ]                    [   ]
[ 4 ]                    [   ]
[ 5 ]                    [   ]
```

このプロジェクトで重要なのは、単に数字をソートすることではありません。

**入力データの乱雑度（disorder）や入力サイズに応じて適切なアルゴリズムを選択し、できるだけ少ない操作数でソートすること**が重要です。

---

# 使用方法

## コンパイル

以下のコマンドでコンパイルします。

```bash
make
```

Makefileには以下のルールを用意します。

```bash
make
make all
make clean
make fclean
make re
```

コンパイルには以下のオプションを使用します。

```text
-Wall -Wextra -Werror
```

また、不必要な再リンクを行わないようにします。

---

## 基本的な実行

```bash
./push_swap 2 1 3 6 5 8
```

出力はPush_swapで使用可能な操作のみで構成されます。

例えば、

```text
sa
ra
pb
```

のように、1行につき1つの操作を出力します。

---

## 引数がない場合

```bash
./push_swap
```

引数がない場合は、何も出力せずに終了します。

---

# スタック操作

Push_swapでは2つのスタックを使用します。

```text
a
b
```

プログラム開始時には、すべての値が `a` に入っており、`b` は空です。

最終的に、スタック `a` を昇順にします。

---

## Swap

### sa

スタック `a` の先頭2つの要素を交換します。

```text
Before        After

1             2
2      →      1
3             3
```

### sb

スタック `b` の先頭2つの要素を交換します。

### ss

`sa` と `sb` を同時に実行します。

スタックに2つ未満の要素しかない場合、そのスタックに対する操作は何もしません。

---

## Push

### pa

`b` の先頭要素を `a` の先頭へ移動します。

```text
A              A
1              3
2      ←       1
               2

B
3
```

### pb

`a` の先頭要素を `b` の先頭へ移動します。

```text
A              A
1              2
2      →       3

B
3
```

---

## Rotate

### ra

`a` の先頭要素を最後へ移動します。

```text
1              2
2      →       3
3              1
```

### rb

`b` の先頭要素を最後へ移動します。

### rr

`ra` と `rb` を同時に実行します。

---

## Reverse Rotate

### rra

`a` の最後の要素を先頭へ移動します。

```text
1              3
2      →       1
3              2
```

### rrb

`b` の最後の要素を先頭へ移動します。

### rrr

`rra` と `rrb` を同時に実行します。

---

# 戦略の選択

本プロジェクトでは4種類のソート戦略を実装します。

| オプション        | 戦略       | 計算量            |
| ------------ | -------- | -------------- |
| `--simple`   | Simple   | `O(n²)`        |
| `--medium`   | Medium   | `O(n√n)`       |
| `--complex`  | Complex  | `O(n log n)`   |
| `--adaptive` | Adaptive | disorderによって選択 |

戦略を指定しなかった場合は、`--adaptive` をデフォルトとして使用します。

```bash
./push_swap --simple 5 3 1 4 2
./push_swap --medium 5 3 1 4 2
./push_swap --complex 5 3 1 4 2
./push_swap --adaptive 5 3 1 4 2
```

どの戦略も、入力サイズや乱雑度に関係なく使用できる必要があります。

---

# 乱雑度（Disorder）

## 定義

Disorderは、入力されたスタックがどの程度ソートされていないかを表す値です。

値は `0` から `1` の範囲になります。

```text
0.0 ─────────────── 1.0
│                     │
完全にソート       最も乱雑
```

例えば、

```text
1 2 3 4 5
```

は完全にソートされているため、

```text
disorder = 0
```

となります。

---

## 計算方法

すべての要素の組 `(i, j)` について、

```c
i < j
```

を満たすペアを調べます。

その中で、

```c
a[i] > a[j]
```

となるペアを「間違ったペア」として数えます。

そして、

```text
disorder = mistakes / total_pairs
```

で計算します。

### 擬似コード

```text
mistakes = 0
total_pairs = 0

for i = 0 ～ size - 1
    for j = i + 1 ～ size - 1
        total_pairs++

        if a[i] > a[j]
            mistakes++

disorder = mistakes / total_pairs
```

Disorderは**スタックに対してソート操作を行う前に計算**します。

---

# アルゴリズム

本プロジェクトでは、以下の4つの戦略を使用します。

```text
                  入力
                   │
                   ▼
              エラーチェック
                   │
                   ▼
            Disorderを計算
                   │
                   ▼
          ┌─────────────────┐
          │ 戦略を選択       │
          └────────┬────────┘
                   │
       ┌───────────┼───────────┐
       │           │           │
       ▼           ▼           ▼
    Simple       Medium      Complex
     O(n²)       O(n√n)     O(n log n)
       │           │           │
       └───────────┼───────────┘
                   │
                   ▼
                Adaptive
                   │
                   ▼
                ソート完了
```

---

# 1. Simple — O(n²)

Simple戦略では、**Selection Sort**を使用します。

## 基本方針

スタック `a` の中から最小値を探します。

```text
A

5
2
4
1
3
```

最小値 `1` の位置を探します。

```text
A

5
2
4
1  ← minimum
3
```

最小値が先頭に近い場合は `ra`、末尾に近い場合は `rra` を使用して最小値を先頭へ移動します。

その後、

```text
pb
```

で `b` へ移動します。

これを `a` が空になるまで繰り返します。

最後に `b` から `a` へ戻します。

---

## アルゴリズム

```text
             Stack A
                │
                ▼
          最小値を探索
                │
                ▼
          最小値の位置
           │          │
        前半        後半
           │          │
           ▼          ▼
          ra         rra
           │          │
           └────┬─────┘
                │
                ▼
                pb
                │
                ▼
             繰り返す
                │
                ▼
              Aが空？
             /      \
           No        Yes
           │          │
           └───→      ▼
                    B → A
```

## 計算量

```text
時間計算量: O(n²)
```

42の仕様では、Simple戦略は `O(n²)` の計算量が求められます。

---

# 2. Medium — O(n√n)

Medium戦略では、**Chunk Sort**を使用します。

Chunk Sortでは、座標圧縮されたindexを複数の範囲に分割して処理します。

例えば、

```text
0 ～ 9
10 ～ 19
20 ～ 29
30 ～ 39
...
```

のようにChunkを作ります。

---

## AからBへの移動

現在処理しているChunkの範囲に入っている要素が `a` の先頭に来たら、

```text
pb
```

で `b` に移動します。

Chunkの範囲外なら、

```text
ra
```

で `a` を回転します。

```text
             Stack A
                │
                ▼
           先頭のindex
                │
          ┌─────┴─────┐
          │           │
       Chunk内      Chunk外
          │           │
          ▼           ▼
         pb          ra
          │
          ▼
       Stack B
```

Bに入れた要素についても、後で効率よくAへ戻せるように `rb` を利用します。

---

## BからAへの移動

Bにすべての要素を移動した後、最大のindexから順番にAへ戻します。

```text
B

9
5
8
2
7
```

最大値 `9` の位置を探します。

位置が先頭に近ければ、

```text
rb
```

を使用します。

末尾に近ければ、

```text
rrb
```

を使用します。

最大値を先頭へ移動したら、

```text
pa
```

でAへ戻します。

これを繰り返します。

---

## アルゴリズム

```text
             Stack A
                │
                ▼
          Chunkを選択
                │
                ▼
       Chunk内の要素を探す
          │            │
       見つかった     見つからない
          │            │
          ▼            ▼
         pb           ra
          │
          ▼
       次の要素
          │
          ▼
       次のChunk
          │
          ▼
       Stack B
          │
          ▼
     最大indexを探索
          │
     ┌────┴────┐
     │         │
    rb        rrb
     │         │
     └────┬────┘
          │
          ▼
          pa
          │
          ▼
       ソート完了
```

## 計算量

```text
時間計算量: O(n√n)
```

42の仕様では、Medium戦略には `O(n√n)` の計算量が求められています。

Chunkを `√n` 個程度に分割する方法がMedium戦略の例として示されています。

---

# 3. Complex — O(n log n)

Complex戦略では、**Radix Sort**を使用します。

Radix Sortでは、座標圧縮されたindexを2進数として扱います。

例えば、

```text
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
```

となります。

---

## ビットの確認

現在処理しているbitが、

```text
0
```

なら、

```text
pb
```

を実行します。

```text
1
```

なら、

```text
ra
```

を実行します。

Cでは以下のようなビット演算を使用できます。

```c
(index >> bit) & 1
```

---

## アルゴリズム

```text
                 Stack A
                    │
                    ▼
                bitを確認
                    │
             ┌──────┴──────┐
             │             │
           bit=0         bit=1
             │             │
             ▼             ▼
            pb            ra
             │             │
             └──────┬──────┘
                    │
                    ▼
                Aを1周処理
                    │
                    ▼
                 B → A
                    │
                    ▼
                次のbit
                    │
                    ▼
                 繰り返す
                    │
                    ▼
                  完了
```

---

## 計算量

```text
時間計算量: O(n log n)
```

42の仕様では、Complex戦略には `O(n log n)` の計算量が求められています。

Radix Sortは、Push_swapの制限された操作に適応できる `O(n log n)` のアルゴリズムとして仕様内でも例として挙げられています。

---

# 4. Adaptive

Adaptive戦略では、入力データの **disorder** に応じて使用するアルゴリズムを切り替えます。

42の仕様で指定されている閾値は以下です。

|      Disorder | 使用する戦略  |          計算量 |
| ------------: | ------- | -----------: |
|       `< 0.2` | Simple  |      `O(n²)` |
| `0.2 ～ < 0.5` | Medium  |     `O(n√n)` |
|       `≥ 0.5` | Complex | `O(n log n)` |

---

## Adaptiveの流れ

```text
                 入力
                   │
                   ▼
           Disorderを計算
                   │
          ┌────────┼────────┐
          │        │        │
        < 0.2   0.2～<0.5   ≥ 0.5
          │        │        │
          ▼        ▼        ▼
       Simple    Medium    Complex
       O(n²)    O(n√n)    O(n log n)
          │        │        │
          └────────┼────────┘
                   │
                   ▼
                ソート完了
```

この方式によって、入力がすでにある程度ソートされている場合と、完全に乱れている場合で異なるアルゴリズムを使用できます。

Adaptiveは、戦略を指定しなかった場合のデフォルト戦略です。

---

# ベンチマークモード

ベンチマークは、

```bash
./push_swap --bench ...
```

で有効にします。

ベンチマーク情報は、**ソート処理が完了した後に標準エラー出力（stderr）へ表示**します。

通常のPush_swap操作は標準出力（stdout）へ出力します。

これにより、

```bash
./push_swap --bench 3 2 1 | ./checker 3 2 1
```

のように、操作出力とベンチマーク情報を分離できます。

---

## ベンチマークで表示する情報

以下の情報を表示します。

1. Disorder
2. 選択された戦略
3. 理論上の計算量
4. 総操作数
5. 各操作の回数

操作数としてカウントするもの：

```text
sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr
```

---

## 出力例

```text
[bench] disorder: 42.50%
[bench] strategy: Medium
[bench] complexity: O(n√n)
[bench] total operations: 1234
[bench] sa: 10
[bench] sb: 0
[bench] ss: 0
[bench] pa: 100
[bench] pb: 100
[bench] ra: 500
[bench] rb: 300
[bench] rr: 0
[bench] rra: 100
[bench] rrb: 124
[bench] rrr: 0
```

---

# エラー処理

入力に問題がある場合、

```text
Error
```

と改行を付けて**標準エラー出力**へ表示します。

---

## 不正な文字

```bash
./push_swap 1 abc 3
```

```text
Error
```

---

## 重複した値

```bash
./push_swap 1 2 2 3
```

```text
Error
```

---

## INTの範囲外

`int` の範囲外の値はエラーです。

```text
-2147483648 ～ 2147483647
```

例えば、

```bash
./push_swap 2147483648
```

はエラーになります。

---

## 技術的選択

`free_stack` は成功時も `-1` を返すようにしています。

これは`main.c` の複数のエラー処理箇所で`free_stack(a); return (-1);` を

`return (free_stack(&a_stack));`という1行にまとめるための意図的な設計です。

---

# 出力仕様

通常の標準出力には、Push_swapの操作だけを出力します。

```text
ra
pb
rb
pa
```

余計なデバッグメッセージなどを標準出力へ出力してはいけません。

ベンチマーク情報は `--bench` が指定された場合のみ標準エラー出力へ表示します。

---

# テスト

## 基本テスト

```bash
./push_swap 2 1 3
```

```bash
./push_swap 3 2 1
```

```bash
./push_swap 1 2 3
```

すでにソートされている場合は、不要な操作を出力しないようにします。

---

## 各戦略のテスト

### Simple

```bash
./push_swap --simple 5 4 3 2 1
```

### Medium

```bash
./push_swap --medium 5 4 3 2 1
```

### Complex

```bash
./push_swap --complex 5 4 3 2 1
```

### Adaptive

```bash
./push_swap --adaptive 5 4 3 2 1
```

### Benchmark

```bash
./push_swap --bench 5 4 3 2 1
```

---

# Checkerを使用したテスト

Push_swapが生成した操作が正しいか確認するため、checkerを使用できます。

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

正しくソートできれば、

```text
OK
```

が表示されます。

---

# 大規模入力のテスト

500個のランダムな数字を生成できます。

```bash
shuf -i 0-9999 -n 500
```

例えば、

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --complex $ARG | wc -l
```

で、生成された操作数を確認できます。

---

# 技術的な選択

## データ構造

スタックには連結リストを使用しています。

ノードには、

```c
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
```

のように、

* `value`
* `index`
* `next`
* `prev`

を保持します。

`next` と `prev` を持つ双方向連結リストにすることで、通常のrotateだけでなくreverse rotateも実装しやすくしています。

---

# 座標圧縮

Radix Sortなどで扱いやすくするため、入力値を順位（index）へ変換します。

例えば、

```text
入力:

50 10 -20 30 5
```

を昇順にすると、

```text
-20 5 10 30 50
```

となります。

それぞれに順位を割り当てると、

```text
-20 → 0
5   → 1
10  → 2
30  → 3
50  → 4
```

元の順番をindexに変換すると、

```text
4 2 0 3 1
```

となります。

これにより、元の整数値そのものではなく、

```text
0 ～ n - 1
```

の範囲でアルゴリズムを処理できます。

特にRadix Sortでは、このindexを2進数として扱います。

---

# アルゴリズムの選択理由

## Simple

Selection Sortは実装が比較的単純で、低いdisorderの入力に対して使用できます。

```text
O(n²)
```

という計算量を持ちます。

---

## Medium

Chunk Sortではデータを複数の範囲に分けて処理することで、一度に扱う要素数を減らします。

```text
O(n√n)
```

を目標とします。

---

## Complex

Radix Sortは、入力をbit単位で処理します。

座標圧縮されたindexを利用することで、入力値の大きさに依存せず処理できます。

```text
O(n log n)
```

の計算量を実現します。

---

## Adaptive

入力のdisorderを事前に計算し、

```text
低いdisorder → Simple
中程度       → Medium
高いdisorder → Complex
```

と切り替えることで、入力データに適したアルゴリズムを選択します。

---

# チームの役割分担

このプロジェクトは2人で作成します。

## `myazawa`

担当：

* 入力チェック
* スタック初期化
* Simple / Selection Sort
* Medium / Chunk Sort
* Complex / Radix Sort
* Adaptive
* Benchmark
* 最適化

## `yudakane`

担当：

* 細々としたバグの修正
* テストケースの試行
* プロジェクトのコードの確認と理解
* 全体の構成や処理の流れの把握

---

# AIの利用について

本プロジェクトでは、AIツールを学習および開発補助として使用しました。

主な利用内容は以下です。

* ソートアルゴリズムの理解
* 計算量の確認
* デバッグ
* コンパイルエラーの原因調査
* READMEなどのドキュメント作成
* テスト方法の検討

AIから得た回答やコードについては、そのまま使用するのではなく、プロジェクトの仕様を確認し、実際にコンパイル・テストした上で使用しています。

最終的なコードについては、プロジェクトメンバー自身が内容を理解し、説明できることを前提としています。

---

# 参考資料

## 42 Push_swap Subject

本プロジェクトの主要な仕様については、42が提供するPush_swapのSubjectを参考にしています。

特に以下についてSubjectを参照しました。

* スタック操作
* ソート戦略
* 計算量
* Disorder
* Adaptive戦略
* Benchmark
* エラー処理
* 性能基準

---

## アルゴリズム

以下のアルゴリズムについて学習・調査しました。

* Selection Sort
* Chunk Sort
* Radix Sort
* Big-O記法
* Inversion
* Disorder
* Stack
* Linked List
* Bitwise Operation

---
