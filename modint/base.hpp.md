---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitrary_ntt.hpp
    title: Arbitrary Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_2d.hpp
    title: Convolution 2D
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_mod_2_64.hpp
    title: Convolution $\pmod{2^{64}}$
  - icon: ':heavy_check_mark:'
    path: convolution/dirichlet_convolution.hpp
    title: Dirichlet Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp_massey.hpp
    title: Berlekamp Massey
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps.hpp
    title: $f(g(x))$ ( $O(N\log^2{N})$ )
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps_old.hpp
    title: $f(g(x))$ ( $O(N^2)$ )
  - icon: ':heavy_check_mark:'
    path: fps/compositional_inverse_of_fps.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570 ( $O(N\\log^2{N})$ )"
  - icon: ':heavy_check_mark:'
    path: fps/compositional_inverse_of_fps_old.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570 ( $O(N^2)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':heavy_check_mark:'
    path: fps/middle_product.hpp
    title: $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$
  - icon: ':heavy_check_mark:'
    path: fps/middle_product_arbitrary.hpp
    title: $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$
  - icon: ':heavy_check_mark:'
    path: fps/multipoint_evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly_fps.hpp
    title: Formal Power Series (NTT Friendly)
  - icon: ':heavy_check_mark:'
    path: fps/polynomial_interpolation.hpp
    title: Polynomial Interpolation
  - icon: ':heavy_check_mark:'
    path: fps/power_projection_of_fps.hpp
    title: "$\\sum_{j}^{n-1} w_j [x^j] f(x)^i$ \u306E $i = 0,1,\\dots,M$ \u306E\u5217\
      \u6319"
  - icon: ':heavy_check_mark:'
    path: fps/product_of_fps.hpp
    title: $\prod f_i$
  - icon: ':heavy_check_mark:'
    path: fps/product_of_one_minus_xn.hpp
    title: $\prod (1 - x^{a_i}) \mod x^d$
  - icon: ':heavy_check_mark:'
    path: fps/product_of_one_plus_xn.hpp
    title: $\prod (1 + x^{a_i}) \mod x^d$
  - icon: ':heavy_check_mark:'
    path: fps/shift_of_sampling_points_of_poly.hpp
    title: Shift of Sampling Points of Polynomial
  - icon: ':heavy_check_mark:'
    path: fps/sum_of_rational_fps.hpp
    title: $\sum \frac{f_i}{g_i}$
  - icon: ':heavy_check_mark:'
    path: fps/taylor_shift.hpp
    title: $f(x + c)$
  - icon: ':heavy_check_mark:'
    path: graph/count_directed_euler_trail.hpp
    title: Count Directed Euler Trail
  - icon: ':heavy_check_mark:'
    path: graph/count_spanning_tree.hpp
    title: Count Spanning Tree
  - icon: ':heavy_check_mark:'
    path: math/DirichletSeries.hpp
    title: Dirichlet Series
  - icon: ':heavy_check_mark:'
    path: math/bernoulli_number.hpp
    title: Bernoulli Number
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: math/catalan_convolution.hpp
    title: Catalan's Convolution Formula
  - icon: ':heavy_check_mark:'
    path: math/catalan_number.hpp
    title: Catalan Number
  - icon: ':heavy_check_mark:'
    path: math/factorial_mod_998.hpp
    title: math/factorial_mod_998.hpp
  - icon: ':heavy_check_mark:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.hpp
    title: Mod Inv
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: Mod Sqrt
  - icon: ':heavy_check_mark:'
    path: math/partition_function.hpp
    title: Partition Function
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_1st.hpp
    title: Stirling Numbers of the First Kind
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_2nd.hpp
    title: Stirling Numbers of the Second Kind
  - icon: ':heavy_check_mark:'
    path: math/sum_of_exp_times_poly.hpp
    title: $\sum_{i = 0}^{n-1} a^i f(i)$
  - icon: ':heavy_check_mark:'
    path: math/sum_of_powers_iota.hpp
    title: $\sum_{i = 0}^{n-1} i^k$
  - icon: ':heavy_check_mark:'
    path: math/sums_of_powers.hpp
    title: "$\\sum_n A_n^i$ \u306E $i = 0, 1,\\dots, k$ \u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/sums_of_powers_iota.hpp
    title: "$\\sum_{i = 0}^{n-1} i^k$ \u306E $k$ \u306B\u95A2\u3059\u308B\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: matrix/det_arbitrary_mod.hpp
    title: matrix/det_arbitrary_mod.hpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic_modint.hpp
    title: modint/dynamic_modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint61.hpp
    title: modint/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery_modint.hpp
    title: modint/montgomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: string/wildcard_pattern_matching.hpp
    title: Wildcard Pattern Matching
  - icon: ':heavy_check_mark:'
    path: tree/rooted_tree_hash.hpp
    title: Rooted Tree Hash
  - icon: ':heavy_check_mark:'
    path: utility/hash.hpp
    title: Hash structure
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2863.test.cpp
    title: test/aoj/aoj_2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_And_Convolution.test.cpp
    title: test/convolution/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_OR_Convolution.test.cpp
    title: test/convolution/Bitwise_OR_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_Xor_Convolution.test.cpp
    title: test/convolution/Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution.test.cpp
    title: test/convolution/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_2D.test.cpp
    title: test/convolution/Convolution_2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_1000000007.test.cpp
    title: test/convolution/Convolution_Mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_2_64.test.cpp
    title: test/convolution/Convolution_Mod_2_64.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Gcd_Convolution.test.cpp
    title: test/convolution/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Lcm_Convolution.test.cpp
    title: test/convolution/Lcm_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Subset_Convolution.test.cpp
    title: test/convolution/Subset_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Deque_Operate_All_Composite.test.cpp
    title: test/data_structure/Deque_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Queue_Operate_All_Composite.test.cpp
    title: test/data_structure/Queue_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
    title: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Parallel_Unionfind.test.cpp
    title: test/data_structure/Range_Parallel_Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
    title: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Counting_Eulerian_Circuits.test.cpp
    title: test/graph/Counting_Eulerian_Circuits.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Counting_Spanning_Trees_Directed.test.cpp
    title: test/graph/Counting_Spanning_Trees_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Counting_Spanning_Trees_Undirected.test.cpp
    title: test/graph/Counting_Spanning_Trees_Undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Berunoulli_Number.test.cpp
    title: test/math/Berunoulli_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Catalan_Convolution.test.cpp
    title: test/math/Catalan_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Factorial.test.cpp
    title: test/math/Factorial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Find_Linear_Recurrence.test.cpp
    title: test/math/Find_Linear_Recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Negative_Binomial_Coefficient.test.cpp
    title: test/math/Negative_Binomial_Coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_FPS.test.cpp
    title: test/math/Partition_Function_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_Pentagonal.test.cpp
    title: test/math/Partition_Function_Pentagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Pow.test.cpp
    title: test/math/Pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sharp_P_Subset_Sum.test.cpp
    title: test/math/Sharp_P_Subset_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sqrt_Mod.test.cpp
    title: test/math/Sqrt_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
    title: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
    title: test/math/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Matrix.test.cpp
    title: test/matrix/Determinant_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Matrix_2.test.cpp
    title: test/matrix/Determinant_of_Matrix_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
    title: test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Inverse_Matrix.test.cpp
    title: test/matrix/Inverse_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Matrix_Product.test.cpp
    title: test/matrix/Matrix_Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Pow_of_Matrix.test.cpp
    title: test/matrix/Pow_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Rank_of_Matrix.test.cpp
    title: test/matrix/Rank_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/System_of_Linear_Equations.test.cpp
    title: test/matrix/System_of_Linear_Equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series_Large.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series_Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series_Large.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series_Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Division_of_Polynomials.test.cpp
    title: test/polynomial/Division_of_Polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Interpolation.test.cpp
    title: test/polynomial/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Shift_of_Sampling_Points_of_Polynomial.test.cpp
    title: test/polynomial/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/set_function/Exp_of_Set_Power_Series.test.cpp
    title: test/set_function/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
    title: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/Wildcard_Pattern_Matching.test.cpp
    title: test/string/Wildcard_Pattern_Matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
    title: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
    title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/tree/Tree_Path_Composite_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1796.test.cpp
    title: test/yuki/yuki_1796.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1857.test.cpp
    title: test/yuki/yuki_1857.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2633.test.cpp
    title: test/yuki/yuki_2633.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2747.test.cpp
    title: test/yuki/yuki_2747.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n\
    #include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint =\
    \ requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n\
    \    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\
    \nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n\
    \    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: modint/base.hpp
  requiredBy:
  - utility/hash.hpp
  - math/partition_function.hpp
  - math/sums_of_powers.hpp
  - math/sum_of_exp_times_poly.hpp
  - math/factorial_mod_998.hpp
  - math/mod_inv.hpp
  - math/catalan_convolution.hpp
  - math/sum_of_powers_iota.hpp
  - math/DirichletSeries.hpp
  - math/stirling_number_1st.hpp
  - math/catalan_number.hpp
  - math/linear_sieve.hpp
  - math/mod_sqrt.hpp
  - math/binomial.hpp
  - math/bernoulli_number.hpp
  - math/stirling_number_2nd.hpp
  - math/sums_of_powers_iota.hpp
  - tree/rooted_tree_hash.hpp
  - fps/shift_of_sampling_points_of_poly.hpp
  - fps/ntt_friendly_fps.hpp
  - fps/power_projection_of_fps.hpp
  - fps/fps.hpp
  - fps/fps_sparse.hpp
  - fps/taylor_shift.hpp
  - fps/compositional_inverse_of_fps_old.hpp
  - fps/polynomial_interpolation.hpp
  - fps/berlekamp_massey.hpp
  - fps/product_of_one_plus_xn.hpp
  - fps/sum_of_rational_fps.hpp
  - fps/compositional_inverse_of_fps.hpp
  - fps/product_of_fps.hpp
  - fps/middle_product_arbitrary.hpp
  - fps/fps_sqrt.hpp
  - fps/composition_of_fps.hpp
  - fps/composition_of_fps_old.hpp
  - fps/multipoint_evaluation.hpp
  - fps/product_of_one_minus_xn.hpp
  - fps/middle_product.hpp
  - graph/count_spanning_tree.hpp
  - graph/count_directed_euler_trail.hpp
  - convolution/convolution_mod_2_64.hpp
  - convolution/dirichlet_convolution.hpp
  - convolution/convolution.hpp
  - convolution/ntt.hpp
  - convolution/convolution_2d.hpp
  - convolution/arbitrary_ntt.hpp
  - matrix/det_arbitrary_mod.hpp
  - modint/dynamic_modint.hpp
  - modint/modint61.hpp
  - modint/modint.hpp
  - modint/montgomery_modint.hpp
  - string/rolling_hash.hpp
  - string/wildcard_pattern_matching.hpp
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Deque_Operate_All_Composite.test.cpp
  - test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  - test/data_structure/Range_Parallel_Unionfind.test.cpp
  - test/data_structure/Queue_Operate_All_Composite.test.cpp
  - test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/Range_Affine_Point_Get.test.cpp
  - test/aoj/aoj_2863.test.cpp
  - test/aoj/aoj_3361.test.cpp
  - test/aoj/aoj_2444.test.cpp
  - test/math/Factorial.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
  - test/math/Berunoulli_Number.test.cpp
  - test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/math/Sharp_P_Subset_Sum.test.cpp
  - test/math/Sum_of_Totient_Function.test.cpp
  - test/math/Partition_Function_FPS.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/math/Pow.test.cpp
  - test/math/Partition_Function_Pentagonal.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
  - test/math/Negative_Binomial_Coefficient.test.cpp
  - test/math/Sqrt_Mod.test.cpp
  - test/math/Catalan_Convolution.test.cpp
  - test/math/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - test/math/Find_Linear_Recurrence.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - test/tree/Tree_Path_Composite_Sum.test.cpp
  - test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - test/graph/Counting_Spanning_Trees_Undirected.test.cpp
  - test/graph/Counting_Eulerian_Circuits.test.cpp
  - test/graph/Counting_Spanning_Trees_Directed.test.cpp
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series_Large.test.cpp
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Division_of_Polynomials.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - test/polynomial/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series_Large.test.cpp
  - test/convolution/Convolution.test.cpp
  - test/convolution/Lcm_Convolution.test.cpp
  - test/convolution/Bitwise_Xor_Convolution.test.cpp
  - test/convolution/Gcd_Convolution.test.cpp
  - test/convolution/Subset_Convolution.test.cpp
  - test/convolution/Bitwise_And_Convolution.test.cpp
  - test/convolution/Convolution_Mod_2_64.test.cpp
  - test/convolution/Convolution_2D.test.cpp
  - test/convolution/Bitwise_OR_Convolution.test.cpp
  - test/convolution/Convolution_Mod_1000000007.test.cpp
  - test/matrix/Pow_of_Matrix.test.cpp
  - test/matrix/System_of_Linear_Equations.test.cpp
  - test/matrix/Determinant_of_Matrix_2.test.cpp
  - test/matrix/Inverse_Matrix.test.cpp
  - test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
  - test/matrix/Matrix_Product.test.cpp
  - test/matrix/Determinant_of_Matrix.test.cpp
  - test/matrix/Rank_of_Matrix.test.cpp
  - test/set_function/Exp_of_Set_Power_Series.test.cpp
  - test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  - test/yuki/yuki_2747.test.cpp
  - test/yuki/yuki_1302.test.cpp
  - test/yuki/yuki_2633.test.cpp
  - test/yuki/yuki_1857.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/yuki/yuki_1796.test.cpp
  - test/string/Wildcard_Pattern_Matching.test.cpp
documentation_of: modint/base.hpp
layout: document
redirect_from:
- /library/modint/base.hpp
- /library/modint/base.hpp.html
title: modint/base.hpp
---
