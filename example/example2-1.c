int f(void){
        float f_var;
        double d_var;
        long double l_d_var;

        f_var = 1; d_var = 1; l_d_var = 1;
        d_var = d_var + f_var;
        l_d_var = d_var + f_var;
        return(l_d_var);
}