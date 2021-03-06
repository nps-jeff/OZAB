// Generated by rstantools.  Do not edit by hand.

/*
    OZAB is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OZAB is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OZAB.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_OZAB_model_probit_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_OZAB_model_probit");
    reader.add_event(69, 67, "end", "model_OZAB_model_probit");
    return reader;
}
template <typename T0__, typename T1__, typename T2__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__>::type, Eigen::Dynamic, 1>
beta_class_cover(const T0__& alpha,
                     const T1__& beta,
                     const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& c, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 5;
        int K(0);
        (void) K;  // dummy to suppress unused var warning
        stan::math::fill(K, std::numeric_limits<int>::min());
        stan::math::assign(K,(num_elements(c) + 1));
        current_statement_begin__ = 7;
        validate_non_negative_index("result", "K", K);
        Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> result(K);
        stan::math::initialize(result, DUMMY_VAR__);
        stan::math::fill(result, DUMMY_VAR__);
        current_statement_begin__ = 9;
        stan::model::assign(result, 
                    stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                    beta_cdf(get_base1(c, 1, "c", 1), alpha, beta), 
                    "assigning variable result");
        current_statement_begin__ = 10;
        for (int k = 2; k <= (K - 1); ++k) {
            current_statement_begin__ = 11;
            stan::model::assign(result, 
                        stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list()), 
                        (beta_cdf(get_base1(c, k, "c", 1), alpha, beta) - sum(stan::model::rvalue(result, stan::model::cons_list(stan::model::index_min_max(1, (k - 1)), stan::model::nil_index_list()), "result"))), 
                        "assigning variable result");
        }
        current_statement_begin__ = 13;
        stan::model::assign(result, 
                    stan::model::cons_list(stan::model::index_uni(K), stan::model::nil_index_list()), 
                    (1 - sum(stan::model::rvalue(result, stan::model::cons_list(stan::model::index_min_max(1, (K - 1)), stan::model::nil_index_list()), "result"))), 
                    "assigning variable result");
        current_statement_begin__ = 15;
        return stan::math::promote_scalar<fun_return_scalar_t__>(result);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
struct beta_class_cover_functor__ {
    template <typename T0__, typename T1__, typename T2__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T1__, T2__>::type, Eigen::Dynamic, 1>
    operator()(const T0__& alpha,
                     const T1__& beta,
                     const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& c, std::ostream* pstream__) const {
        return beta_class_cover(alpha, beta, c, pstream__);
    }
};
template <bool propto, typename T1__, typename T2__, typename T3__, typename T4__>
typename boost::math::tools::promote_args<T1__, T2__, T3__, T4__>::type
ozab_lpmf(const std::vector<int>& y,
              const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& theta,
              const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& alpha,
              const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& beta,
              const Eigen::Matrix<T4__, Eigen::Dynamic, 1>& c, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T1__, T2__, T3__, T4__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 19;
        local_scalar_t__ result(DUMMY_VAR__);
        (void) result;  // dummy to suppress unused var warning
        stan::math::initialize(result, DUMMY_VAR__);
        stan::math::fill(result, DUMMY_VAR__);
        stan::math::assign(result,0);
        current_statement_begin__ = 22;
        int N(0);
        (void) N;  // dummy to suppress unused var warning
        stan::math::fill(N, std::numeric_limits<int>::min());
        stan::math::assign(N,num_elements(y));
        current_statement_begin__ = 24;
        for (int n = 1; n <= N; ++n) {
            current_statement_begin__ = 25;
            if (as_bool(logical_eq(get_base1(y, n, "y", 1), 0))) {
                current_statement_begin__ = 26;
                stan::math::assign(result, (result + bernoulli_log(1, get_base1(theta, n, "theta", 1))));
            } else {
                current_statement_begin__ = 28;
                stan::math::assign(result, (result + (bernoulli_log(0, get_base1(theta, n, "theta", 1)) + categorical_log(get_base1(y, n, "y", 1), beta_class_cover(get_base1(alpha, n, "alpha", 1), get_base1(beta, n, "beta", 1), c, pstream__)))));
            }
        }
        current_statement_begin__ = 32;
        return stan::math::promote_scalar<fun_return_scalar_t__>(result);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
template <typename T1__, typename T2__, typename T3__, typename T4__>
typename boost::math::tools::promote_args<T1__, T2__, T3__, T4__>::type
ozab_lpmf(const std::vector<int>& y,
              const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& theta,
              const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& alpha,
              const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& beta,
              const Eigen::Matrix<T4__, Eigen::Dynamic, 1>& c, std::ostream* pstream__) {
    return ozab_lpmf<false>(y,theta,alpha,beta,c, pstream__);
}
struct ozab_lpmf_functor__ {
    template <bool propto, typename T1__, typename T2__, typename T3__, typename T4__>
        typename boost::math::tools::promote_args<T1__, T2__, T3__, T4__>::type
    operator()(const std::vector<int>& y,
              const Eigen::Matrix<T1__, Eigen::Dynamic, 1>& theta,
              const Eigen::Matrix<T2__, Eigen::Dynamic, 1>& alpha,
              const Eigen::Matrix<T3__, Eigen::Dynamic, 1>& beta,
              const Eigen::Matrix<T4__, Eigen::Dynamic, 1>& c, std::ostream* pstream__) const {
        return ozab_lpmf(y, theta, alpha, beta, c, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_OZAB_model_probit
  : public stan::model::model_base_crtp<model_OZAB_model_probit> {
private:
        int N;
        int K;
        vector_d c;
        std::vector<int> y;
        int Kp;
        int Ka;
        matrix_d Xa;
        matrix_d Xp;
        double prior_mean;
        double prior_var;
public:
    model_OZAB_model_probit(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_OZAB_model_probit(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_OZAB_model_probit_namespace::model_OZAB_model_probit";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 37;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 0);
            current_statement_begin__ = 38;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 2);
            current_statement_begin__ = 39;
            validate_non_negative_index("c", "(K - 1)", (K - 1));
            context__.validate_dims("data initialization", "c", "vector_d", context__.to_vec((K - 1)));
            c = Eigen::Matrix<double, Eigen::Dynamic, 1>((K - 1));
            vals_r__ = context__.vals_r("c");
            pos__ = 0;
            size_t c_j_1_max__ = (K - 1);
            for (size_t j_1__ = 0; j_1__ < c_j_1_max__; ++j_1__) {
                c(j_1__) = vals_r__[pos__++];
            }
            stan::math::check_positive_ordered(function__, "c", c);
            current_statement_begin__ = 40;
            validate_non_negative_index("y", "N", N);
            context__.validate_dims("data initialization", "y", "int", context__.to_vec(N));
            y = std::vector<int>(N, int(0));
            vals_i__ = context__.vals_i("y");
            pos__ = 0;
            size_t y_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < y_k_0_max__; ++k_0__) {
                y[k_0__] = vals_i__[pos__++];
            }
            size_t y_i_0_max__ = N;
            for (size_t i_0__ = 0; i_0__ < y_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "y[i_0__]", y[i_0__], 0);
                check_less_or_equal(function__, "y[i_0__]", y[i_0__], K);
            }
            current_statement_begin__ = 41;
            context__.validate_dims("data initialization", "Kp", "int", context__.to_vec());
            Kp = int(0);
            vals_i__ = context__.vals_i("Kp");
            pos__ = 0;
            Kp = vals_i__[pos__++];
            check_greater_or_equal(function__, "Kp", Kp, 0);
            current_statement_begin__ = 42;
            context__.validate_dims("data initialization", "Ka", "int", context__.to_vec());
            Ka = int(0);
            vals_i__ = context__.vals_i("Ka");
            pos__ = 0;
            Ka = vals_i__[pos__++];
            check_greater_or_equal(function__, "Ka", Ka, 0);
            current_statement_begin__ = 43;
            validate_non_negative_index("Xa", "N", N);
            validate_non_negative_index("Xa", "Ka", Ka);
            context__.validate_dims("data initialization", "Xa", "matrix_d", context__.to_vec(N,Ka));
            Xa = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, Ka);
            vals_r__ = context__.vals_r("Xa");
            pos__ = 0;
            size_t Xa_j_2_max__ = Ka;
            size_t Xa_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < Xa_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < Xa_j_1_max__; ++j_1__) {
                    Xa(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 44;
            validate_non_negative_index("Xp", "N", N);
            validate_non_negative_index("Xp", "Kp", Kp);
            context__.validate_dims("data initialization", "Xp", "matrix_d", context__.to_vec(N,Kp));
            Xp = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(N, Kp);
            vals_r__ = context__.vals_r("Xp");
            pos__ = 0;
            size_t Xp_j_2_max__ = Kp;
            size_t Xp_j_1_max__ = N;
            for (size_t j_2__ = 0; j_2__ < Xp_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < Xp_j_1_max__; ++j_1__) {
                    Xp(j_1__, j_2__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 45;
            context__.validate_dims("data initialization", "prior_mean", "double", context__.to_vec());
            prior_mean = double(0);
            vals_r__ = context__.vals_r("prior_mean");
            pos__ = 0;
            prior_mean = vals_r__[pos__++];
            current_statement_begin__ = 46;
            context__.validate_dims("data initialization", "prior_var", "double", context__.to_vec());
            prior_var = double(0);
            vals_r__ = context__.vals_r("prior_var");
            pos__ = 0;
            prior_var = vals_r__[pos__++];
            check_greater_or_equal(function__, "prior_var", prior_var, 0);
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 50;
            validate_non_negative_index("mu_beta", "Ka", Ka);
            num_params_r__ += Ka;
            current_statement_begin__ = 51;
            validate_non_negative_index("theta_beta", "Kp", Kp);
            num_params_r__ += Kp;
            current_statement_begin__ = 52;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_OZAB_model_probit() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 50;
        if (!(context__.contains_r("mu_beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu_beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu_beta");
        pos__ = 0U;
        validate_non_negative_index("mu_beta", "Ka", Ka);
        context__.validate_dims("parameter initialization", "mu_beta", "vector_d", context__.to_vec(Ka));
        Eigen::Matrix<double, Eigen::Dynamic, 1> mu_beta(Ka);
        size_t mu_beta_j_1_max__ = Ka;
        for (size_t j_1__ = 0; j_1__ < mu_beta_j_1_max__; ++j_1__) {
            mu_beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(mu_beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu_beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 51;
        if (!(context__.contains_r("theta_beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable theta_beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("theta_beta");
        pos__ = 0U;
        validate_non_negative_index("theta_beta", "Kp", Kp);
        context__.validate_dims("parameter initialization", "theta_beta", "vector_d", context__.to_vec(Kp));
        Eigen::Matrix<double, Eigen::Dynamic, 1> theta_beta(Kp);
        size_t theta_beta_j_1_max__ = Kp;
        for (size_t j_1__ = 0; j_1__ < theta_beta_j_1_max__; ++j_1__) {
            theta_beta(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(theta_beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable theta_beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 52;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "phi", "double", context__.to_vec());
        double phi(0);
        phi = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 50;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> mu_beta;
            (void) mu_beta;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_beta = in__.vector_constrain(Ka, lp__);
            else
                mu_beta = in__.vector_constrain(Ka);
            current_statement_begin__ = 51;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> theta_beta;
            (void) theta_beta;  // dummy to suppress unused var warning
            if (jacobian__)
                theta_beta = in__.vector_constrain(Kp, lp__);
            else
                theta_beta = in__.vector_constrain(Kp);
            current_statement_begin__ = 52;
            local_scalar_t__ phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.scalar_lb_constrain(0, lp__);
            else
                phi = in__.scalar_lb_constrain(0);
            // model body
            current_statement_begin__ = 62;
            lp_accum__.add(normal_log<propto__>(mu_beta, prior_mean, prior_var));
            current_statement_begin__ = 63;
            lp_accum__.add(normal_log<propto__>(theta_beta, prior_mean, prior_var));
            current_statement_begin__ = 66;
            lp_accum__.add(ozab_lpmf<propto__>(y, Phi(multiply(Xp, theta_beta)), multiply(phi, Phi(multiply(Xa, mu_beta))), multiply(phi, subtract(1, Phi(multiply(Xa, mu_beta)))), c, pstream__));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu_beta");
        names__.push_back("theta_beta");
        names__.push_back("phi");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(Ka);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(Kp);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_OZAB_model_probit_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> mu_beta = in__.vector_constrain(Ka);
        size_t mu_beta_j_1_max__ = Ka;
        for (size_t j_1__ = 0; j_1__ < mu_beta_j_1_max__; ++j_1__) {
            vars__.push_back(mu_beta(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> theta_beta = in__.vector_constrain(Kp);
        size_t theta_beta_j_1_max__ = Kp;
        for (size_t j_1__ = 0; j_1__ < theta_beta_j_1_max__; ++j_1__) {
            vars__.push_back(theta_beta(j_1__));
        }
        double phi = in__.scalar_lb_constrain(0);
        vars__.push_back(phi);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_OZAB_model_probit";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t mu_beta_j_1_max__ = Ka;
        for (size_t j_1__ = 0; j_1__ < mu_beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu_beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t theta_beta_j_1_max__ = Kp;
        for (size_t j_1__ = 0; j_1__ < theta_beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta_beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t mu_beta_j_1_max__ = Ka;
        for (size_t j_1__ = 0; j_1__ < mu_beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu_beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t theta_beta_j_1_max__ = Kp;
        for (size_t j_1__ = 0; j_1__ < theta_beta_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta_beta" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_OZAB_model_probit_namespace::model_OZAB_model_probit stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
