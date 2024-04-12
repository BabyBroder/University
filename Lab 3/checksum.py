
def split_string_hex(string):
    hex_bytes = []
    res = []
    for i in range(0, len(string), 2):
        hex_bytes.append("0x" + string[i:i+2].zfill(2))
    for i in range(0, len(hex_bytes), 2):
        res.append(hex_bytes[i] + hex_bytes[i+1][2::])
    return res

def split_ip(string):
    hex_bytes = []
    arr_ip = string.split(".")
    for i in range(0, len(arr_ip), 2):
        hex_bytes.append(hex(int(arr_ip[i], 10)) + hex(int(arr_ip[i+1], 10))[2:])
    return hex_bytes

def reverse_bit(bin):
    res = ""
    for i in bin:
        if(i == '1'):
            res += '0'
        if(i == '0'):
            res += '1'
    return res
 
def binary_to_hex(binary_string):
  if not isinstance(binary_string, str):
    raise TypeError("Input must be a binary string")

  if not all(char in "01" for char in binary_string):
    raise ValueError("Invalid binary string. Only 0s and 1s allowed.")

  decimal_value = int(binary_string, 2)

  hex_string = hex(decimal_value)[2:]  

  return hex_string       

def int_to_binary(number, num_bits):

  binary_string = ""
  while number > 0:
    remainder = number % 2
    binary_string = str(remainder) + binary_string
    number //= 2

  padded_string = "0" * (num_bits - len(binary_string)) + binary_string
  return padded_string

#ip_source = "172.20.41.120"
#ip_dest = "186.186.4.200"
#source_port = 56976
#des_port = 35614
#length = 56
#udp_data = "906c4d5e1a1eee51000029bfbede000112e714df922562354d2b38a4c2f02c3cf41924f898cd0f565dc93cfb4599f6e1"
#check_sum must be : 0x0853

ip_source = input("Input Ip of Source: ")
ip_dest = input("Input Ip of Destination: ")
source_port = int(input("Input port of Source: "))
des_port = int(input("Input port of Destination: "))
length = int(input("Input length: "))
udp_data = input("Input payload: ")


arr_source = split_ip(ip_source)
arr_dest = split_ip(ip_dest)



checksum = (source_port)
checksum += (des_port)
checksum += (length)
checksum += (length)
checksum += int(0x0011)             #udp: 0x0011

for i in range (2):
    checksum += int(arr_source[i], 16)
    checksum += int(arr_dest[i], 16)
    
udp_hex_arr = split_string_hex(udp_data)
for i in udp_hex_arr:
    checksum += int(i, 16)


checksum_str = "{:#x}".format(checksum)
if(len(checksum_str[2::]) > 4):
    division = "0x" + checksum_str[-4::]
    remainder = checksum_str[:-4]
    checksum_int = int(division, 16) + int(remainder, 16)
    checksum_bin = reverse_bit(int_to_binary(checksum_int, 18)[2::])
    checksum = binary_to_hex(checksum_bin)

while(len(checksum) < 4):
    checksum = "0" + checksum
    
print("Check sum: " + "0x" + checksum) 

