#typedef unsigned char byte;

void drawLine(unsigned char screen[], int width, int x1, int x2, int y) {
	int start_offset = x1 % 8;
	int first_full_byte = x1 / 8;
	if(first_offset != 0)
		++first_full_byte;

	int end_offset = x2 % 8;
	int last_full_byte = x2 / 8;
	if(end_offset != 0)
		--last_full_byte;

	for(int b = first_full_byte; b <= last_full_byte; ++b)
		screen[(width / 8) * y + b] = (unsigned char)0xFF;

	byte start_mask = (unsigned char)(0xFF >> start_offset);
	byte end_mask = (byte) ~(0xFF >> (end_offset+1));

	if((x1/8) == (x2/8))
		screen[(width / 8) * y + (x1 / 8)] |= (start_mask | end_mask);
	else {
		if(start_offset != 0) {
			int byte_number = (width / 8) * y + first_full_byte - 1;
			screen[byte_number] |= start_mask;
		}
		if(end_offset != 7) {
			int byte_number = (width / 8) * y + last_full_byte + 1;
			screen[byte_number] |= end_mask;
		}
	}
}
