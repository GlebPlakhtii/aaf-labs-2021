from R_Tree_To_compile.built.R_Tree import R_Tree, Rect


class Table:
    def __init__(self, name):
        self.name = name
        self.tree = R_Tree()

    def insert(self, x, y):
        self.tree.insert(Rect(x, y, x, y))
        root = str(self.tree.get_root())

    def search(self, ltx, lty, rbx, rby):
        for n in self.tree.search(Rect(ltx, lty, rbx, rby)):
            print(n)

    def is_contain(self, x, y):
        return self.tree.is_contain(Rect(x, y, x, y))

    def print_tree(self):
        self.tree.print_tree()

    def left_of(self, x):
        root = str(self.tree.get_root())
        ltx = float(root.split(',')[0].replace('((', ''))
        lty = float(root.split(')')[0].split()[-1])
        rby = float(root.split()[-1].replace('))', ''))

        for n in self.tree.search(Rect(ltx, lty, x, rby)):
            print(n)

    def nn(self, x, y):
        for n in self.tree.nn(Rect(x, y, x, y)):
            print(n)
