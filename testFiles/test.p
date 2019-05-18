program main(input,output);
    
    
    var a,b: integer;
    var x,y,z: real;

    function foo(b: integer) : integer;

        procedure bar(b : real);
        begin
            z := 2.718 (* illegal because called from function *)
        end;

    begin
        (* x:= 3.14 illegal nonlocal name *)
        bar(1.1);
        foo := 2*b
    end;

    procedure boo(p: integer; q: real; r: real);
        var a: real;
        var z: integer;
    begin
        x := 3.14; (* legal because procedure *)
        writeln(p+13);
        writeln(p+14);
        writeln(p+15) (* semicolon is separator, not terminator *)
    end;

begin

    boo(foo(13),2.5,3.2);
    boo(2,4.5)
end.
