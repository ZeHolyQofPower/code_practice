module logic_vs_bitwise( 
    input [2:0] a,
    input [2:0] b,
    output [2:0] out_or_bitwise,
    output out_or_logical,
    output [5:0] out_not
);
    assign out_or_bitwise = a | b;
    assign out_or_logical = a || b;
    
    logic [5:0]b_cat_a;
    assign b_cat_a = {b, a};
    assign out_not = ~b_cat_a;

endmodule
