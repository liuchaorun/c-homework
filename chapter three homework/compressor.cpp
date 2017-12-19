//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <bitset>
//#include <map>
//#include <fstream>
//#include <cassert>
//
//#include "my_queue.h"
//
//using namespace std;
//
//string ONE("1"),ZERO("0");
//
//class bufferArea{
//private:
//    int current;
//    int max;
//    uint8_t code;
//public:
//    bufferArea();
//    ~bufferArea();
//    void buffer(uint8_t code,int size,ofstream& out);
//    int buffer_all(ofstream& out);
//};
//
//bufferArea::bufferArea() {
//    current = 0;
//    max = 8;
//    code = 0;
//}
//
//bufferArea::~bufferArea()=default;
//
//void bufferArea::buffer(uint8_t c,int size, ofstream &out) {
//    for(int i = 0 ;i<size;++i){
//        if(current == 8){
//            out<<code;
//            current = 0;
//            code = 0;
//        }
//        if(c&(1<<(2-i))) code |= (1<<(7-current));
//        current ++;
//    }
//}
//
//int bufferArea::buffer_all(ofstream &out) {
//    if(current){
//        out<<code;
//        return current;
//    }
//    else{
//        return 0;
//    }
//}
//
//class huffmanCode{
//private:
//    uint8_t code;
//    uint8_t length;
//    uint8_t reCode;
//    double probability;
//public:
//    huffmanCode(uint8_t reCode, uint8_t code, uint8_t length, double probability);
//    ~huffmanCode();
//    void setCode(uint8_t code);
//    void setlength(uint8_t length);
//    void setReCode(uint8_t reCode);
//    void setProbability(double probability);
//    uint8_t getCode();
//    uint8_t getLength();
//    uint8_t getReCode();
//    double getProbability();
//};
//
//huffmanCode::huffmanCode(uint8_t reCode, uint8_t code, uint8_t length, double probability):reCode(reCode),code(code),length(length),probability(probability) {}
//
//huffmanCode::~huffmanCode()=default;
//
//void huffmanCode::setCode(uint8_t code) {
//    this->code = code;
//}
//
//void huffmanCode::setlength(uint8_t length) {
//    this->length = length;
//}
//
//void huffmanCode::setReCode(uint8_t reCode) {
//    this->reCode = reCode;
//}
//
//void huffmanCode::setProbability(double probability) {
//    this->probability = probability;
//}
//
//uint8_t huffmanCode::getCode() {
//    return code;
//}
//
//uint8_t huffmanCode::getLength() {
//    return length;
//}
//
//uint8_t huffmanCode::getReCode() {
//    return reCode;
//}
//
//double huffmanCode::getProbability() {
//    return probability;
//}
//
//class huffmanNode{
//private:
//    uint8_t code;
//    huffmanNode* leftChild;
//    huffmanNode* rightChild;
//    double probability;
//public:
//    huffmanNode(uint8_t code,double probability,huffmanNode* leftChild,huffmanNode* rightChild);
//    ~huffmanNode();
//    void setCode(uint8_t code);
//    void setProbability(double probability);
//    void setLeftChild(huffmanNode* leftChild);
//    void setRightChild(huffmanNode* rightChild);
//    uint8_t getCode();
//    double getProbability();
//    huffmanNode* getLeftChild();
//    huffmanNode* getRightChild();
//    bool operator==(huffmanNode& HCode);
//    bool operator>(huffmanNode& HCode);
//    bool operator<(huffmanNode& HCode);
//};
//
//huffmanNode::huffmanNode(uint8_t code, double probability, huffmanNode *leftChild, huffmanNode *rightChild):code(code),probability(probability),leftChild(leftChild),rightChild(rightChild) {}
//
//huffmanNode::~huffmanNode()=default;
//
//void huffmanNode::setCode(uint8_t code) {
//    this->code = code;
//}
//
//void huffmanNode::setProbability(double probability) {
//    this->probability = probability;
//}
//
//void huffmanNode::setLeftChild(huffmanNode *leftChild) {
//    this->leftChild = leftChild;
//}
//
//void huffmanNode::setRightChild(huffmanNode *rightChild) {
//    this->rightChild = rightChild;
//}
//
//uint8_t huffmanNode::getCode() {
//    return code;
//}
//
//double huffmanNode::getProbability() {
//    return probability;
//}
//
//huffmanNode* huffmanNode::getLeftChild() {
//    return leftChild;
//}
//
//huffmanNode* huffmanNode::getRightChild() {
//    return rightChild;
//}
//
//bool huffmanNode::operator==(huffmanNode &HCode) {
//    return probability == HCode.getProbability();
//}
//
//bool huffmanNode::operator>(huffmanNode &HCode) {
//    return probability > HCode.getProbability();
//}
//
//bool huffmanNode::operator<(huffmanNode &HCode) {
//    return probability < HCode.getProbability();
//}
//
//class huffmanTree{
//private:
//    huffmanNode* root;
//public:
//    huffmanTree();
//    ~huffmanTree();
//    void buildHuffmanTree(vector<huffmanNode*> code);
//    bool createCodeTable(vector<huffmanCode*>& codeTable);
//    void createCode(vector<huffmanCode*>& codeTable,uint8_t i,bitset<8> *bits,huffmanNode* temp);
//};
//
//huffmanTree::huffmanTree() {
//    root = nullptr;
//}
//
//huffmanTree::~huffmanTree() {
//    if(!root){
//        queue<huffmanNode*> huffmanNodeQueue;
//        huffmanNodeQueue.en_queue(root);
//        huffmanNode *temp;
//        while(huffmanNodeQueue.get_size()==0){
//            huffmanNodeQueue.de_queue(temp);
//            if(temp->getLeftChild()){
//                huffmanNodeQueue.en_queue(temp->getLeftChild());
//            }
//            if(temp->getRightChild()){
//                huffmanNodeQueue.en_queue(temp->getRightChild());
//            }
//            delete(temp);
//        }
//    }
//}
//
//void huffmanTree::buildHuffmanTree(vector<huffmanNode*> code) {
//    huffmanNode* left,* right;
//    sort(code.begin(),code.end());//从小到大排序
//    while (code.size() != 1){
//        left = code[0];
//        right = code[1];
//        code.erase(code.begin(),code.begin()+2);
//        code.push_back(new huffmanNode(0, left->getProbability() + right->getProbability(), left, right));
//        sort(code.begin(),code.end());
//    }
//    root = code[0];
//}
//
//void huffmanTree::createCode(vector<huffmanCode *> &codeTable, uint8_t i, bitset<8> *bits, huffmanNode *temp) {
//    string a = bits->to_string().substr((uint8_t)(8-i),7);
//    if(temp->getLeftChild()->getCode()==0){
//        createCode(codeTable,i+(uint8_t)1,new bitset<8>(a+ZERO),temp->getLeftChild());
//    }
//    else{
//        bitset <8> b(a+ZERO);
//        uint8_t reCode = 0;
//        for(uint8_t j =0;j<i+1;++j){
//            if(b.test(j)){
//                reCode |= (b[j]<<j);
//            }
//        }
//        codeTable.push_back(new huffmanCode(reCode,temp->getLeftChild()->getCode(),i+1,temp->getLeftChild()->getProbability()));
//    }
//    if(temp->getRightChild()->getCode()==0){
//        createCode(codeTable,i+(uint8_t)1,new bitset<8>(a+ONE),temp->getRightChild());
//    }
//    else{
//        bitset <8> b(a+ONE);
//        uint8_t reCode = 0;
//        for(uint8_t j =0;j<i+1;++j){
//            if(b.test(j)){
//                reCode |= (b[j]<<j);
//            }
//        }
//        codeTable.push_back(new huffmanCode(reCode,temp->getRightChild()->getCode(),i+1,temp->getRightChild()->getProbability()));
//    }
//}
//
//bool huffmanTree::createCodeTable(vector<huffmanCode *> &codeTable) {
//    bitset<8> *bits;
//    bits = new bitset<8>;
//    createCode(codeTable,0,bits,root);
//}
//
//class compressor{
//private:
//    huffmanTree HTree;
//    vector<huffmanCode*> codeTable;
//    vector<huffmanNode*> code;
//    int colorSum;
//    int imgWidth;
//    int imgLength;
//    map<uint8_t,huffmanCode*> codeMap;
//    bufferArea buffer;
//public:
//    compressor();
//    ~compressor();
//    void compress(ifstream& in,ofstream& out);
//    void deCompress(ifstream& in,ofstream& out);
//    void createCode(vector<huffmanNode*>& c);
//    void createCodeMap();
//    void buildHTree();
//};
//
//compressor::compressor() {}
//
//compressor::~compressor()=default;
//
//void compressor::createCode(vector<huffmanNode *> &c) {}
//
//void compressor::buildHTree() {}
//
//void compressor::createCodeMap() {}
//
//void compressor::compress(ifstream &in,ofstream& out) {
//    int row=1,col=0;
//    string a;
//    map<uint8_t,int> elementsMap;
//    in >> noskipws;
//    uint8_t c;
//    in>>c;
//    while(!in.eof()){
//        if(c=='\n'){
//            row++;
//            col =0;
//        }
//        else{
//            if(c!='\r'){
//                col++;
//                map<uint8_t,int>::iterator it= elementsMap.find(c);
//                if(it == elementsMap.end()) {
//                    elementsMap.insert(map<uint8_t,int>::value_type(c,1));
//                }
//                else {
//                    elementsMap[c]++;
//                }
//            }
//        }
//        in>>c;
//    }
//    for(map<uint8_t,int>::iterator it= elementsMap.begin();it!=elementsMap.end();it++){
//        code.push_back(new huffmanNode(it->first,(it->second)*1.0/(col*row*1.0), nullptr, nullptr));
//    }
//    HTree.buildHuffmanTree(code);
//    HTree.createCodeTable(codeTable);
//    for(vector<huffmanCode*>::iterator it = codeTable.begin();it!=codeTable.end();++it){
//        codeMap.insert(map<uint8_t,huffmanCode*>::value_type((*it)->getCode(),(*it)));
//    }
//    out<<'S'<<'C'<<'N'<<'H'<<"W"<<col<<"H"<<row<<endl;
//    for(map<uint8_t,huffmanCode*>::iterator it = codeMap.begin();it!=codeMap.end();++it){
//        out<<it->first<<it->second->getLength()<<it->second->getReCode();
//    }
//    out<<endl;
//    in.clear();
//    in.seekg(0,ios::beg);
//    in>>c;
//    while(!in.eof()){
//        if(c!='\n'&&c!='\r'){
//            buffer.buffer(c,codeMap[c]->getLength(),out);
//        }
//        in>>c;
//    }
//    uint8_t i =(uint8_t) buffer.buffer_all(out);
//    if(i){
//        out<<endl<<i;
//        cout<<(int)i;
//    }
//    else{
//        cout<<"p";
//    }
//    in.close();
//    out.close();
//}
//
//void compressor::deCompress(ifstream &in, ofstream &out) {
//    int row,col;
//    uint8_t c,r;
//    uint8_t length;
//    char a[4],b;
//    in >> noskipws;
//    in >> a[0] >> a[1] >> a[2] >> a[3] ;
//    in>>b>> col>>b >> row ;
//    in>>c;
//    if(a[0]=='S'&&a[1]=='C'&&a[2]=='N'&&a[3]=='H'){
//        in>>c;
//        while(c!='\n'){
//            in>>length;
//            in>>r;
//            codeMap.insert(map<uint8_t,huffmanCode*>::value_type(r,new huffmanCode(r,c,length,0)));
//            in>>c;
//        }
//        in>>c;
//
//    }
//    else{
//        cout<<"错误的文件类型！"<<endl;
//    }
//    in.close();
//    out.close();
//}
//
//int main(){
//    string path("D:///2.dat"),wPath("D:///3.dat");
//    compressor c;
//    //cin>>path;
//    ifstream infile;
//    infile.open(path,ios::binary);
//    ofstream outfile;
//    outfile.open(wPath,ios::binary);
//    //c.compress(infile,outfile);
//    c.deCompress(infile,outfile);
//    return 0;
//}
//