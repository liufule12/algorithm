# encoding = utf-8
__author__ = 'Fule Liu'


from numpy import *
from numpy.ma import multiply, log, exp
from numpy.core.umath import sign


def data_process(read_file):
    """ Load data."""
    dat_mat = []
    class_labels = []
    with open(read_file) as f_read:
        lines = f_read.readlines()
        for line in lines:
            temp_vec = []
            for ind, item in enumerate(line.rstrip().split()):
                if ind < 2:
                    temp_vec.append(float(item))
                else:
                    class_labels.append(float(item))
            dat_mat.append(temp_vec)

    return matrix(dat_mat), class_labels


def load_simp_data():
    """ Simple load data for demo."""
    dat_mat = matrix([[1., 2.1],
                     [2., 1.1],
                     [1.3, 1.],
                     [1., 1.],
                     [2., 1.]])
    class_labels = [1.0, 1.0, -1.0, -1.0, 1.0]

    return dat_mat, class_labels


def stump_classify(data_matrix, dimen, thresh_val, thresh_ineq):
    ret_array = ones((shape(data_matrix)[0], 1))
    if thresh_ineq == 'lt':
        ret_array[data_matrix[:, dimen] <= thresh_val] = -1.0
    else:
        ret_array[data_matrix[:, dimen] > thresh_val] = -1.0

    return ret_array


def build_stump(data_arr, class_labels, d):
    data_matrix = mat(data_arr)
    label_mat = mat(class_labels).T
    m, n = shape(data_matrix)
    num_steps = 10.0
    best_stump = {}
    best_clas_est = mat(zeros((m, 1)))
    min_error = inf

    for i in range(n):
        range_min = data_matrix[:, i].min()
        range_max = data_matrix[:, i].max()
        step_size = (range_max - range_min) / num_steps

        for j in range(-1, int(num_steps) + 1):
            for inequal in ['lt', 'gt']:
                thresh_val = (range_min + float(j) * step_size)
                predicted_vals = stump_classify(data_matrix, i, thresh_val, inequal)
                err_arr = mat(ones((m, 1)))
                err_arr[predicted_vals == label_mat] = 0
                # print("D: ", d.T)
                # print("err_arr: ", err_arr)
                weighted_error = d.T * err_arr
                # print("split: dim %d, thresh %.2f, thresh inequal: %s, the weighted error is %.3f" %
                #       (i, thresh_val, inequal, weighted_error))

                # print("weighted_error: ", weighted_error)
                # print("min_error:", min_error)
                # print(weighted_error.sum())
                # if weighted_error.sum() < min_error:
                if weighted_error < min_error:
                    min_error = weighted_error
                    best_clas_est = predicted_vals.copy()
                    best_stump['dim'] = i
                    best_stump['thresh'] = thresh_val
                    best_stump['ineq'] = inequal

    return best_stump, min_error, best_clas_est


def ada_boost_train_ds(data_arr, class_labels, num_it=40):
    weak_class_arr = []
    m = shape(data_arr)[0]
    d = mat(ones((m, 1)) / m)
    agg_class_est = mat(zeros((m, 1)))
    for i in range(num_it):
        best_stump, error, class_est = build_stump(data_arr, class_labels, d)
        # print("D:", d.T)

        alpha = float(0.5 * log((1.0 - error) / max(error, 1e-16)))
        best_stump['alpha'] = alpha
        weak_class_arr.append(best_stump)
        print("ClassEst: ", class_est.T)

        expon = multiply(-1 * alpha * mat(class_labels).T, class_est)
        d = multiply(d, exp(expon))
        d = d / d.sum()
        # print("D:", d)

        agg_class_est += alpha * class_est
        print("agg_class_est: ", agg_class_est.T)

        agg_errors = multiply(sign(agg_class_est) != mat(class_labels).T, ones((m, 1)))
        error_rate = agg_errors.sum() / m
        print("Total error: ", error_rate)
        if error_rate == 0.0:
            break

    return weak_class_arr


if __name__ == "__main__":
    dat_mat, class_labels = load_simp_data()
    D = mat(ones((5, 1)) / 5)
    print(build_stump(dat_mat, class_labels, D))

    # classifier_array = ada_boost_train_ds(dat_mat, class_labels, 9)

    # dat_mat, class_labels = data_process("hw2_adaboost_train.dat")
    # D = mat(ones((len(class_labels), 1)) / len(class_labels))
    # best_stump, error, class_est = build_stump(dat_mat, class_labels, D)
    # print("Best_stump:", best_stump)
    # print("Min_error:", error)
    # classifier_array = ada_boost_train_ds(dat_mat, class_labels, 9)
