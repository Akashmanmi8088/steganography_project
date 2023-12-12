#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc,char *argv[])
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;
    uint img_size;   
    if(argc<3)
    {
        printf("Enter minuimum 3 arguments");
        return 1;
    }
    if(check_operation_type(argv)==e_encode)
    {
        printf("Encoding\n");
        if(read_and_validate_encode_args(argv,&encInfo)==e_success)
        {
            printf("validated succesfully\n");
            if(do_encoding(&encInfo)==e_success)
            {
                printf("Encoded successfully\n");
            } 
            else
            {
                printf("encoding is not done\n");
            }
        }
        else
        {
            printf("Failed to Validate");
        }
    }
    else if(check_operation_type(argv)==e_decode)
    {
        printf("Decoding\n");  
        if(read_and_validate_decode_args(argv,&decInfo)==d_success)
        {
            printf("File Validate successfully\n");
            if(do_decoding(&decInfo)==d_success)
            {
                printf("Decoded successfully.\n");
            }
            else
            {
                printf("decoding is not done\n");
            }
        }
        else
        {
            printf("Usage: Fail decode");
        }
    }
    else
    {
        printf("Usage:\\ (-e,-d ) Please enter correct value ");
    }

    return 0;
}
