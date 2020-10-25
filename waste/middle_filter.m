function [ output_img ] = middle_filter( input_img, filter_size )
%ÖĞÖµÂË²¨

    [M,N] = size(input_img);
    offset = (filter_size-1)/2;
    m = M - 2*offset;
    n = N - 2*offset;
    output_img = zeros(m,n);
    for i = 1+offset:M-offset
        for j = 1+offset:N-offset
            filter = input_img(i-offset:i+ofset,j-offset:j+offset);
            sort_filter = sort(filter);
            output_img(i-offset,j-offset) = sort_filter(filter_size^2-1);
        end
    end
    output_img = uint8(output_img);
end


function [ output_array ] = sort( input_array )
%ÅÅĞò

    output_array = input_array;
    [M,N] = size(output_array);

    for i = 1:N
        for j = i+1:N
           if  output_array(j) > output_array(i)
               temp = output_array(i);
               output_array(i) = output_array(j);
               output_array(j) = temp;
           end
        end
    end

end
