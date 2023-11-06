#include <Python.h>

/**
 * print_python_list_info - This function print a object lists.
 * @p: A python object list printed.
 */
void print_python_list_info(PyObject *p)
{
	int s, all, index;
	PyObject *obj;

	s = Py_SIZE(p);
	all = ((PyListObject *)p)->allocated;

	printf("[*] Size of the Python List = %d\n", s);
	printf("[*] Allocated = %d\n", all);

	for (index = 0; index < s; index++)
	{
		printf("Element %d: ", index);

		obj = PyList_GetItem(p, index);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}

