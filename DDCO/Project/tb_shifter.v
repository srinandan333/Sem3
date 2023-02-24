module tb;
reg [15:0] i;
reg [3:0] s;
wire [15:0] o;

initial begin
$dumpfile("dump.vcd");
$dumpvars(0,tb);
end

barrelshifter uut(.i(i),.s(s),.o(o));

initial begin
$monitor("Input=%d, Shift=%d, Output=%d",i,s,o);
i = 16'b1111111111111111; 
s = 4'b0000; 
#200;

i = 16'b1111111111111111; 
s = 4'b0001; 
#200;

i = 16'b1111111111111111; 
s = 4'b0010; 
#200;

i = 16'b1111111111111111; 
s = 4'b0100; 
#200;

i = 16'b1111111111111111; 
s = 4'b1000; 
#200;

i = 16'b1111111111111111; 
s = 4'b0000; 
#200;
end
endmodule