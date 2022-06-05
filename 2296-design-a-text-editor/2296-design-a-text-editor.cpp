class TextEditor {
public:
    string left, right;
    TextEditor() {
    }
    
    void addText(string text) {
        // left=left+text;
        left.append(text);
    }
    
    int deleteText(int k) {
        int lsz = left.size();
        k=min(lsz, k);
        left = left.substr(0, lsz-k);
        return k;
    }
    
    string cursorLeft(int k) {
        int lsz = left.size();
        k = min(k, lsz);
        while(k--)
        {
            right.push_back(left.back());
            left.pop_back();
        }
        
//         cout<<"left: "<<left<<endl;
//         cout<<"right: "<<right<<endl;
        if(left.size()<=10)    return left;
        else return left.substr(left.size()-10);
    }
    
    string cursorRight(int k) {
        int rsz = right.size();
        k=min(k, rsz);
        int i=0;
        while(i<k)
        {
            left.push_back(right.back());
            right.pop_back();
            i++;
        }
        
        if(left.size()<=10)    return left;
        else return left.substr(left.size()-10);
        // cout<<"left: "<<left<<endl;
        // cout<<"right: "<<right<<endl;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */