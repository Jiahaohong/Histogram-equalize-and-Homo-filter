function [ output_img ] = histogram_equalize( input_img )

    [M,N] = size(input_img);
    output_img = zeros(M,N); %初始化输出图像

    %统计原图像灰度直方图
    gray_histogram = count_gray(input_img);
%     figure(25565);
%     subplot(2,2,1);
%     bar(gray_histogram);
%     xlim([0 255]);
%     title('orig gray histogram');

    %计算累计直方图
    acc_gray_histogram = acc_gray(gray_histogram);
%     subplot(2,2,2);
%     bar(acc_gray_histogram);
%     xlim([0 255]);
%     title('acc gray histogram');

    %灰度转换
    gray_trans = acc_gray_histogram*255;
    gray_trans = uint8(round(gray_trans));
%     subplot(2,2,3);
%     bar(gray_trans);
%     xlim([0 255]);
%     title('gray trans');
    
    for i = 1:M
        for j = 1:N
            gray_level = input_img(i,j);
            output_img(i,j) = gray_trans(gray_level+1);
        end
    end   
    output_img = uint8(output_img);
    
    %统计转换后图像的灰度直方图
    new_gray_histogram = count_gray(output_img);
%     subplot(2,2,4);
%     bar(new_gray_histogram);
%     xlim([0 255]);
%     title('new gray histogram');

end