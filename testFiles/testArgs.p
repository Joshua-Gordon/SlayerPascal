program main(input,output);

    procedure boo(a: real; b: integer; c: integer);
    begin
        b := c;
        a := 2.718
    end;

begin
    boo(3.14,2,4);
    boo(1,1);
    boo(4.2,5.43,2.3,5.3)
end.
