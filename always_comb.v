// synthesis verilog_input_version verilog_2001
module always_comb(
    input a, 
    input b,
    output wire out_assign,
    output reg out_alwaysblock
);
    assign out_assign = (a & b);
    
    always @(*) out_alwaysblock = (a & b);
    // always_comb doesn't exist in Verilog2001 😩
endmodule
