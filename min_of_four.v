module min_of_four (
    input [7:0] a, b, c, d,
    output [7:0] min
);
    logic [7:0]min_of_a_b;
    logic [7:0]min_of_c_d;
    // 2-1 Mux finding the min of inputs.
    assign min_of_a_b = (a < b? a : b);
    // 2-1 Mux finding the min of inputs.
    assign min_of_c_d = (c < d? c : d);
    // 2-1 Mux finding the min of intermediate minimums.
    assign min = (min_of_a_b < min_of_c_d? min_of_a_b : min_of_c_d);
endmodule