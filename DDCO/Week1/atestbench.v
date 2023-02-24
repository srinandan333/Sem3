module tb;
reg t_a;
reg t_b;
wire P,Q,R,S;
not1 a1(.i0(t_a),.o1(P));
and2 a2(.i0(t_a),.i1(t_b),.o2(Q));
or2 a3(.i0(t_a),.i1(t_b),.o3(R));
xor2 a4(.i0(t_a),.i1(t_b),.o4(S));
initial begin 
$dumpfile("dump.vcd");
$dumpvars(0,tb);
end
initial begin 
$monitor(t_a,t_b,P,Q,R,S); 
t_a=1'b0;
t_b=1'b0;
#10 
t_a=1'b0;
t_b=1'b1;
#10 
t_a=1'b1;
t_b=1'b0;
#10 
t_a=1'b1;
t_b=1'b1;
#10 
t_a=0;
t_b=0;
end
endmodule

