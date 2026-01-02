libft

説明
libcにあるライブラリにある関数のなかから特によく使うもの40個ほど自ら実装しました。

この課題を行った動機
この課題を取り組んだ時、プログラミングがほぼ未経験の状態であり、
C言語の標準ライブラリの中身が実際にどうなっているのかを肌で感じつつ、
一般的な理系大学生がプログラミング授業で取り組むような基礎的なアルゴリズム力をつけられるために取り組みました。

苦労した点

libcにも入っている関数は本家を忠実に再現できるようすることと、そうでない関数はとにかくクラッシュやオーバーフロー、リークをしないようにした点です。
当初全ての関数で、クラッシュをさせないようにしていたのですが、本家の関数では引数にNULLをいれるとあえてクラッシュさせるものやft_strlcpyの第3引数の扱いに苦労しました。
ft_strlcpyは第三引数のdstsize - 1 バイト分だけ第二引数を第一引数にコピーする仕様なのですが、dstsizeが0のときはhttps://man.openbsd.org/strlcpy.3にあるように
(If the src and dst strings overlap, the behavior is undefined.If dstsize is 0, strlcpy() returns the length of src and nothing is copied.)
src の長さを返すだけで、コピーは一切行われずsrcを触らないようにするなどのテスターを通ること以上に本家を忠実にさいげんしました。
またatoiはオーバーフローやアンダーフローはman 3 atoiにstrtol() and strtoul() にならうようにと記述があったので、オーバフロー時にはINT_MAXをINT_MINを返すにしました。
