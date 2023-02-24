module TB;
reg A,B,S;
wire X;
mux2 newMUX(.i0(A), .i1(B), .j(S), .o(X));
initial
begin
$dumpfile("dump.vcd");
$dumpvars(0,TB);
end
initial
begin
$monitor(A,B,S,X);
S = 1'b0;
A = 1'b0;
B = 1'b0;
#5
A = 1'b0;
B = 1'b1;
#5
A = 1'b1;
B = 1'b0;
#5
A = 1'b1;
B = 1'b1;
#5
S = 1'b1;
A = 1'b0;
B = 1'b0;
#5
A = 1'b0;
B = 1'b1;
#5
A = 1'b1;
B = 1'b0;
#5
A = 1'b1;
B = 1'b1;
end
endmodule
