module carry_select_adder(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    // First stage adders resolve cin with a Mux
    logic [0:0]stage1_carry0;
    add16 add16_instance0(.a(a[15:0]), .b(b[15:0]), .cin(1'b0), .sum(sum[15:0]), .cout(stage1_carry0));
    // Second stage adders contain cin guesses.
    logic [15:0]zero_carry_sum;
    logic [15:0]one_carry_sum;
    add16 add16_instance1(.a(a[31:16]), .b(b[31:16]), .cin(1'b0), .sum(zero_carry_sum), .cout(/* Intentionally Empty */));
    add16 add16_instance2(.a(a[31:16]), .b(b[31:16]), .cin(1'b1), .sum(one_carry_sum), .cout(/* Intentionally Empty */));
    // 2-1 Mux for 2nd stage's correct cin guess.
    always_comb begin
        unique case (stage1_carry0)
            1'b0: sum[31:16] = zero_carry_sum;
            1'b1: sum[31:16] = one_carry_sum;
            default: /* Intentionally Empty */ ;
        endcase
    end
endmodule