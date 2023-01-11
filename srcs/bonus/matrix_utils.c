#include "mini_rt_bonus.h"

// https://theory.stanford.edu/~arbrad/pfe/06/matrix.c

t_matrix	*create_matrix(int n_row, int n_col)
{
	t_matrix	*m;
	int 		i;

	if (n_row <= 0 || n_col <= 0)
		return (0);
	m = malloc(sizeof(*m));
	m->n_row = n_row;
	m->n_col = n_col;
	m->data = malloc(n_row * n_col * sizeof(*m->data));
	i = 0;
	while (i < n_row * n_col)
		m->data[i++] = 0;
	return (m);
}

void	delete_matrix(t_matrix *mtx)
{
	if (!mtx)
		return ;
	free(mtx->data);
	free(mtx);
}

double	matrix_get(t_matrix *mtx, int row, int col)
{
	if (row < 0 || row >= mtx->n_row ||
		col < 0 || col >= mtx->n_col)
		return (mtx->data[0]);
	return (mtx->data[col * mtx->n_row + row]);
}

void	matrix_set(t_matrix *mtx, int row, int col, double val)
{
	if (row < 0 || row >= mtx->n_row ||
		col < 0 || col >= mtx->n_col)
		return ;
	mtx->data[col * mtx->n_row + row] = val;
}

t_matrix	*matrix_multiply(t_matrix *mtx1, t_matrix *mtx2)
{
	t_matrix	*res;
	int			row;
	int			col;
	int			k;
	double		val;

	if (mtx1->n_col != mtx2->n_row)
		return (0);
	res = create_matrix(mtx1->n_row, mtx2->n_col);
	col = -1;
	while (++col < mtx2->n_col)
	{
		row = -1;
		while (++row < mtx1->n_row)
		{
			val = 0;
			k = -1;
			while (++k < mtx1->n_col)
				val += matrix_get(mtx1, row, k) * matrix_get(mtx2, k, col);
			matrix_set(res, row, col, val);
		}
	}
	return (res);
}

t_matrix	*get_orientation_matrix(t_point xaxis, t_point yaxis, t_point zaxis)
{
	t_matrix	*res;

	res = create_matrix(4, 4);

	matrix_set(res, 0, 0, xaxis.x);
	matrix_set(res, 0, 1, yaxis.x);
	matrix_set(res, 0, 2, zaxis.x);
	matrix_set(res, 0, 3, 0);

	matrix_set(res, 1, 0, xaxis.y);
	matrix_set(res, 1, 1, yaxis.y);
	matrix_set(res, 1, 2, zaxis.y);
	matrix_set(res, 1, 3, 0);

	matrix_set(res, 2, 0, xaxis.z);
	matrix_set(res, 2, 1, yaxis.z);
	matrix_set(res, 2, 2, zaxis.z);
	matrix_set(res, 2, 3, 0);

	matrix_set(res, 3, 0, 0);
	matrix_set(res, 3, 1, 0);
	matrix_set(res, 3, 2, 0);
	matrix_set(res, 3, 3, 1);

	return (res);
}

t_matrix	*get_translation_matrix(t_point eye)
{
	t_matrix	*res;

	res = create_matrix(4, 4);

	matrix_set(res, 0, 0, 1);
	matrix_set(res, 0, 1, 0);
	matrix_set(res, 0, 2, 0);
	matrix_set(res, 0, 3, 0);

	matrix_set(res, 1, 0, 0);
	matrix_set(res, 1, 1, 1);
	matrix_set(res, 1, 2, 0);
	matrix_set(res, 1, 3, 0);

	matrix_set(res, 2, 0, 0);
	matrix_set(res, 2, 1, 0);
	matrix_set(res, 2, 2, 1);
	matrix_set(res, 2, 3, 0);

	matrix_set(res, 3, 0, -eye.x);
	matrix_set(res, 3, 1, -eye.y);
	matrix_set(res, 3, 2, -eye.z);
	matrix_set(res, 3, 3, 1);

	return (res);
}

t_matrix	*get_view_matrix(t_point xaxis, t_point yaxis, t_point zaxis, t_point eye)
{
	t_matrix	*res;

	res = create_matrix(4, 4);

	matrix_set(res, 0, 0, xaxis.x);
	matrix_set(res, 0, 1, yaxis.x);
	matrix_set(res, 0, 2, zaxis.x);
	matrix_set(res, 0, 3, 0);

	matrix_set(res, 1, 0, xaxis.y);
	matrix_set(res, 1, 1, yaxis.y);
	matrix_set(res, 1, 2, zaxis.y);
	matrix_set(res, 1, 3, 0);

	matrix_set(res, 2, 0, xaxis.z);
	matrix_set(res, 2, 1, yaxis.z);
	matrix_set(res, 2, 2, zaxis.z);
	matrix_set(res, 2, 3, 0);

	matrix_set(res, 3, 0, -vector_dot(xaxis, eye));
	matrix_set(res, 3, 1, -vector_dot(yaxis, eye));
	matrix_set(res, 3, 2, -vector_dot(zaxis, eye));
	matrix_set(res, 3, 3, 1);

	return (res);
}
