// synthesis verilog_input_version verilog_2001
module three_combinational_assignments(
    input clk,
    input a,
    input b,
    output wire out_assign,
    output reg out_always_comb,
    output reg out_always_ff   );
    // Continual, combinational, memory-less, and asynchronous.
    assign out_assign = (a ^ b);
    // Blocking, combinational, memory-less, and asynchronous. "Level triggered"
    //always_comb begin
    always @(*) begin
        out_always_comb = (a ^ b);
    end
    // Blocking, combinational, memory-less, and clocked. "Edge triggered"
    //always_ff @(posedge clk) begin
    always @(posedge clk) begin
        out_always_ff = (a ^ b);
    end

endmodule