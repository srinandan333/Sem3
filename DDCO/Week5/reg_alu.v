//program for combination of register and alu 
module mux2_16(input wire [15:0] a, b, input wire s, output wire [15:0] o);

mux2 a_0(a[0],b[0],s,o[0]);
mux2 a_1(a[1],b[1],s,o[1]);
mux2 a_2(a[2],b[2],s,o[2]);
mux2 a_3(a[3],b[3],s,o[3]);
mux2 a_4(a[4],b[4],s,o[4]);
mux2 a_5(a[5],b[5],s,o[5]);
mux2 a_6(a[6],b[6],s,o[6]);
mux2 a_7(a[7],b[7],s,o[7]);
mux2 a_8(a[8],b[8],s,o[8]);
mux2 a_9(a[9],b[9],s,o[9]);
mux2 a_10(a[10],b[10],s,o[10]);
mux2 a_11(a[11],b[11],s,o[11]);
mux2 a_12(a[12],b[12],s,o[12]);
mux2 a_13(a[13],b[13],s,o[13]);
mux2 a_14(a[14],b[14],s,o[14]);
mux2 a_15(a[15],b[15],s,o[15]);

endmodule

module reg_alu( input wire clk, reset, sel, wr, input wire [1:0] op, input wire [2:0] rd_addr_a, rd_addr_b, wr_addr, input wire [15:0] d_in, output wire [15:0] d_out_a, d_out_b, output wire out);
wire [15:0] o, d_in1;
wire cout;

mux2_16 b_0( d_in, o, sel, d_in1);

reg_file b_1( clk, reset, wr,  rd_addr_a, rd_addr_b, wr_addr, d_in, d_out_a, d_out_b);

alu b_2( op, d_out_a, d_out_b, o, cout);

dfr b_3( clk, reset, cout, out);

endmodule
