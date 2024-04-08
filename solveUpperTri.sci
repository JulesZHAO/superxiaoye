function x=solveUpperTri(A,b)
    n=size(A,1);
    x=zeros(n,1);
    x(n)=b(n)/A(n,n);
    for i=n-1:-1:1
        x(i)=(b(i)-A(i,i+1:n)*x(i+1:n))/A(i,i);
    end
endfunction
L=[3 2 1;0 2 1;0 0 1];
b=[1 -1 1]';

x=solveUpperTri(L,b);
disp(x)

