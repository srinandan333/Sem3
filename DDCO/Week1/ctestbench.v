module tb;
reg t_a,t_b,t_c;
wire t_s,t_z;
sum1 a1(.a(t_a),.b(t_b),.c(t_c),.s(t_s));
carry1 a2(.a(t_a),.b(t_b),.c(t_c),.z(t_z));
initial begin 
$dumpfile("dump.vcd");
$dumpvars(0,tb);
end
initial begin 
$monitor(t_a,t_b,t_c,t_s,t_z); 
t_a=1'b0;
t_b=1'b0;
t_c=1'b0;
#10 
t_a=1'b0;
t_b=1'b0;
t_c=1'b1;
#10 
t_a=1'b0;
t_b=1'b1;
t_c=1'b0;
#10 
t_a=1'b0;
t_b=1'b1;
t_c=1'b1;
#10 
t_a=1'b1;
t_b=1'b0;
t_c=1'b0;
#10 
t_a=1'b1;
t_b=1'b0;
t_c=1'b1;
#10 
t_a=1'b1;
t_b=1'b1;
t_c=1'b0;
#10 
t_a=1'b1;
t_b=1'b1;
t_c=1'b1;
#10
t_a=1'b0;
t_b=1'b0;
t_c=1'b0;
end
endmodule
