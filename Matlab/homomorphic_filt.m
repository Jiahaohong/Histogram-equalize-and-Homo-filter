function [ output_img ] = homomorphic_filt( input_img, rL, rH, c, d )

%同态滤波参数设置
%rL = 0.1; %低频放大系数
%rH = 5; %高频放大系数
%c = 0.2; %高斯变换常数系数
%d = 1000; %高斯变换系数

[M,N] = size(input_img);
input_img = double(input_img);

log_img = log(input_img+1);
ft_img = fft2(log_img);

%构造高斯滤波器
H = zeros(M,N);
% y0 = floor(M/2);
% x0 = floor(N/2);
for i = 1:M
    for j = 1:N
        D = ((i).^2+(j).^2);
        H(i,j) = (rH-rL).*(1-exp(-c.*(D./(d^2))))+rL;
    end
end

filted_img = H.*ft_img;
ift_img = ifft2(filted_img);
exp_img = exp(ift_img);
output_img = uint8( 255 * (exp_img - ones(M,N)*min(min(exp_img))) / (max(max(exp_img)) - min(min(exp_img))) );
%output_img = uint8(abs(exp_img));
end

