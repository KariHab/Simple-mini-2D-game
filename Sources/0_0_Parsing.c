

#include "../Headers/so_long.h"

/*we need to check the file extension is .ber*/
int check_extension_map_file(char *map_file_name)
{
    size_t name_file_len;

    name_file_len = strlen(map_file_name);
    if((map_file_name[name_file_len - 4] != '.' && map_file_name[name_file_len - 3] != 'b' && map_file_name[name_file_len -2] != 'e' && map_file_name[name_file_len - 1] != 'r'))
        return (-1);
    else
        return (0);
    //we need to return -1 if error 
}

/*we need to check if we have C E P 0 1 in the map*/
int check_chars_in_map(map *letters)
{
    if(letter[index][index_2]) == 'C'
}
/*we need to check if we have wall all around the map*/

/*we need to make sure the map is rectangle*/

/*check the whole map*/