module carry_adder_from_scratch (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);//
  logic [15:0]carry0;
  add16 add16_instance0(.a(a[15:0]), .b(b[15:0]), .cin(1'b0), .sum(sum[15:0]), .cout(carry0));
  add16 add16_instance1(.a(a[31:16]), .b(b[31:16]), .cin(carry0), .sum(sum[31:16]), .cout(/* Intentionally Empty */));
endmodule


module add1 (
    input a,
    input b,
    input cin,
    output sum,
    output cout
);
    logic [1:0]two_bit_sum;
    assign two_bit_sum = (a + b + cin);
    assign sum = two_bit_sum[0:0];
    assign cout = two_bit_sum[1:1];
endmodule
