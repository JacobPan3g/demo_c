# List in class-style

本打算使用函数指针来实现List的成员方法，通过list->push()的方式来调用list的成员
函数，但是，后来实现起来发现，成员函数的第一个参数还是需要输入list本身，因此，
如此实现并不比使用c-style便捷很多，(ps: c-style使用的时list_push())，并且还需
在list结构体里添加多个函数指针，因此，后面还是觉得使用c-style实现List比较实际。

