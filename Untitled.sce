N=5;

h=1/N;
x=0:h:1;

A=zeros(N-1,N-1)
A(1,1:2)=[-2 1]
for i=2:N-2
    A(i,i-1:i+1)=[1 -2 1]
end
A(N-1,N-2:N-1)=[1 -2];
A=-A/h^2;

f1=ones(N-1,1);
f2=sin(pi*x(2:N));

[L,U]=factorizeLU(A);
