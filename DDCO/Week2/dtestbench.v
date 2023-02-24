module TB;
reg [3:0] i1;
reg [3:0] i2;
reg c1;
wire [3:0] o1;
wire o2;
rcadder add1(.a(i1), .b(i2),.cin(c1),.s(o1), .cout(o2));
initial
begin
$dumpfile("dump.vcd");
$dumpvars(0, TB);
end
initial
begin
i1 = 4'b0001;
i2= 4'b0010;
c1= 1'b0;
#5
i1 = 4'b0011;
i2= 4'b1010;
c1= 1'b0;
#5
i1 = 4'b1101;
i2= 4'b0110;
c1= 1'b0;
#5
i1 = 4'b0111;
i2= 4'b1110;
c1= 1'b0;
#5
i1 = 4'b0111;
i2= 4'b1110;
c1= 1'b0;
end
endmodule
