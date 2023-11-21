#include <stdio.h>
#include <stdlib.h>
#include <Python.h>
#include <floatobject.h>

/**
 * print_python_float - prints info about a Python float object
 * @p: address of PyObject struct
 */
void print_python_float(PyObject *p)
{
	double value;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");

	if (strcmp(p->ob_type->tp_name, "float"))
	{
	printf("	[ERROR] Invalid Float Object\n");
	return;
	}

	value = ((PyFloatObject *)p)->ob_fval;
	printf("	value: %s\n",
	 PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL));
}

/**
 * print_python_bytes - prints info about a Python bytes object
 * @p: address of PyObject struct
 */
void print_python_bytes(PyObject *p)
{
	size_t i, len, size;
	char *str;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");

	if (strcmp(p->ob_type->tp_name, "bytes"))
	{
	printf("	[ERROR] Invalid Bytes Object\n");
	return;
	}

	size = ((PyVarObject *)p)->ob_size;
	str = ((PyBytesObject *)p)->ob_sval;
	len = (size + 1 > 10) ? 10 : size + 1;

	printf("	size: %lu\n", size);
	printf("	trying string: %s\n", str);
	printf("	first %lu bytes: ", len);

	for (i = 0; i < len; i++)
	{
	printf("%02hhx%s", str[i], (i + 1 < len) ? " " : "");
	}

	printf("\n");
}
