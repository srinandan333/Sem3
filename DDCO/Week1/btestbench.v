module tb;
reg t_a,t_b;
wire t_s,t_c;
sum1 a1(.a(t_a),.b(t_b),.s(t_s));
carry1 a2(.a(t_a),.b(t_b),.c(t_c));
initial begin 
$dumpfile("dump.vcd");
$dumpvars(0,tb);
end
initial begin 
$monitor(t_a,t_b,t_s,t_c); 
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
t_a=1'b0;
t_b=1'b0;
end
endmodule

