__author__ = 'Fule Liu'

"""Page_rank demo.
   This file is for MMDs homework1 question3.
"""


def pow_iteration(mat_a, vec_r, _iter):
    """PageRank formula: vec_r = mat_a * vec_r
    """
    if _iter == 0:
        return vec_r

    new_r = []
    for line in mat_a:
        two_vec = zip(line, vec_r)
        new_r.append(sum([a * b for a, b in two_vec]))

    return pow_iteration(mat_a, new_r, _iter - 1)


if __name__ == '__main__':
    mat_a = [[0, 0, 1.0],
             [0.5, 0, 0],
             [0.5, 1.0, 0]]
    vec_r = [1.0, 1.0, 1.0]

    for _iter in range(10):
        print(_iter, pow_iteration(mat_a, vec_r, _iter))