%数字图像处理-直方图均值化和规定化-均值滤波和中值滤波
orig_img = imread('1.jpg');
gray_img = rgb2gray(orig_img);
figure(1);
imshow(orig_img);
title('orig img');

figure(2);
subplot(1,2,1);
imshow(gray_img);
title('gray img');
gray_ft_img = fftshift(myft3(gray_img));
g_ft_img = abs(log(gray_ft_img)+1);
subplot(1,2,2);
imshow(g_ft_img,[]);
title('fft gray img');


%直方图均衡化
equalized_img = histogram_equalize(gray_img);
figure(3);
imshow(equalized_img,[]);
title('equalized img');


%同态滤波
homo_filted_img = homomorphic_filt(gray_img,0.1,5,0.2,8000);
figure(4);
imshow(homo_filted_img,[]);
title('homo filted img');

%二者傅里叶频谱图
equa_ft_img = fftshift(myft3(equalized_img));
e_ft_img = abs(log(equa_ft_img)+1);
homo_ft_img = fftshift(myft3(homo_filted_img));
h_ft_img = abs(log(homo_ft_img)+1);
figure(5);
subplot(2,2,1);
imshow(e_ft_img,[]);
title('equalized ft img');
subplot(2,2,2);
imshow(h_ft_img,[]);
title('homo filted ft img');
subplot(2,2,3);
imshow(e_ft_img - g_ft_img);
title('equalized vs gray');
subplot(2,2,4);
imshow(h_ft_img - g_ft_img);
title('homo filted vs gray');
