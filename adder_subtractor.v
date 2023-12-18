module adder_subtractor(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
  logic [15:0]carry0;
  logic [31:0]sign_adjusted_b;
  assign sign_adjusted_b = (b ^ {32{sub}});

  add16 add16_instance0(.a(a[15:0]), .b(sign_adjusted_b[15:0]), .cin(sub), .sum(sum[15:0]), .cout(carry0));
  add16 add16_instance1(.a(a[31:16]), .b(sign_adjusted_b[31:16]), .cin(carry0), .sum(sum[31:16]), .cout(/* Intentionally Empty */));
endmodule