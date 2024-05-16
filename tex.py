from pycparser import c_parser, c_ast, parse_file

# 解析できないトークンを削除したCファイルをパース
ast = parse_file('amain.c', use_cpp=False)

# 関数と変数を保存するためのリスト
functions = []
variables = []

# 関数と変数を抽出するためのVisitorクラス
class FuncDefVisitor(c_ast.NodeVisitor):
    def visit_FuncDef(self, node):
        functions.append(node.decl.name)
        for decl in node.body.block_items:
            if isinstance(decl, c_ast.Decl):
                variables.append(decl.name)

# Visitorを作成してASTを走査
v = FuncDefVisitor()
v.visit(ast)

# 結果を出力
print('Functions:')
for func in functions:
    print(func)

print('Variables:')
for var in variables:
    print(var)