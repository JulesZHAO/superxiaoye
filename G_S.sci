function Gauss_Seidel_z(A,b,e,M)
//A 的对角线元素均不为 0	e: 精度	M: 最大计算次数
//y: 方程的解

n = 3;
x0 = zeros(n,1);
y = zeros(n,1);

[l,w] = size(A);

//矩阵形式

D = diag(diag(A),0);
U = triu(-A,1); //上三角矩阵
L = tril(-A,-1); //下三角矩阵
B = (inv(D-L))*U;
f = (inv(D-L))*b';
for i = 1:M
    y = B*x0+f;
    d = abs(x0-y);
    if(max(d)<e)
        break;
    end
    x0 = y;
end
disp(y);
endfunction

