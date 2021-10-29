#include "R_Tree.h"
#include "Rect.h"
#include <pybind11/pybind11.h>


namespace py = pybind11;

PYBIND11_MODULE(R_Tree, m) {
py::class_<Rect>(m, "Rect")
.def(py::init<int,int,int,int>(), py::arg("ltx"),py::arg("lty"),py::arg("rbx"),py::arg("rby"))
.def("__repr__", &Rect::to_string);

py::class_<R_Tree>(m, "R_Tree")
.def(py::init<>())
.def("insert", &R_Tree::incert, "insert Rect into tree", py::arg("Rect"))
.def("search", &R_Tree::search , "search elements in rect", py::arg("Rect"))
.def("to_string", &R_Tree::to_string, "tree to string")
.def("print_tree", &R_Tree::print_tree, "print tree");


}
