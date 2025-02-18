void decompressing(const char* inp, const char* out, int lenght, NODE* root, char* codes[]) {
    FILE* input = fopen(inp, "rb");
    if (!input) {
        cout << "Can't open file for reading" << endl;
        fclose(input);
        return;
    }
    FILE* output = fopen(out, "wb");
    if (!output) {
        cout << "Can't open file for writing" << endl;
        fclose(output);
        return;
    }
    long count = 0;
    NODE* node = root;
    int byte;
    while ((byte = fgetc(input)) != EOF && count < lenght) {
        for (int i = BYTE - 1; i >= 0; i--) {
            int bit = (byte >> i) & 1;
            if (bit == 0) node = node->left;
            else node = node->right;
            if (node->isSymb == 1) {
                fputc(node->symb, output);
                count++;
                node = root;
            }
        }
    }
    fclose(input);
    fclose(output);
    cout << "File succesfully decompressed!" << endl;
}