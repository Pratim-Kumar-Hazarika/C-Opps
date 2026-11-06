#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//abstraction for document elements
class DocumentElement {
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement {
    private:
        string text;
    public:
        TextElement(string x){
            this->text = x;
        }

        string render() override {
            return text;
        }

};

class ImageElement : public DocumentElement {
    private:
        string image;
    public:
        ImageElement(string x){
            this->image = x;
        }

        string render() override {
            return "[Image : " + image + "]";
        }

};

class NewLine : public DocumentElement {
    public:
        string render() override {
            return "\n";
        };
};


class TabSpace : public DocumentElement {
    public:
        string render () override {
            return "\t";
        };
};

class Document {
    private:
        vector <DocumentElement*> documentElements;
    public:
        void addDocumentElements(DocumentElement* ele){
            documentElements.push_back(ele);
        }

        string render(){
            string text;
            for(auto element :documentElements ){
                text += element->render();
            }
            return text;
        }
};

class Persistence{
    public:
        virtual void save(string data) = 0;
};

class FileStorage : public Persistence {
    public:
        void save (string data) override {
            ofstream outputfile("document.txt");
            if(outputfile){
                    outputfile << data;
                    outputfile.close();
                    cout << "Document saved to document.txt" << endl;

            }else{
                cout << "Unable to save the file.." << endl;
            }
        }
};

class DBStorage : public Persistence {
public:
    void save(string data) override {
         cout << "Save to db" <<endl;
    }
};

class DocumentEditor {
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;
    public:
        DocumentEditor(Document* document, Persistence* storage){
            this->document = document;
            this->storage = storage;
        }

        void addText(string text){
            document->addDocumentElements(new TextElement(text));
        };

        void addImage(string imagePath){
            document->addDocumentElements(new ImageElement(imagePath));
        };

        void addNewLine(){
            document->addDocumentElements(new NewLine());
        };

        void addTabSpace(){
            document->addDocumentElements(new TabSpace());
        };
        string render(){
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
        }

        void saveDocument() {
        storage->save(render());
    }

};

int main(){
    Document* document = new Document();
    Persistence* storage = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document,storage);

    editor->addText("Hello I am pratim");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");
    editor->addNewLine();
    cout << editor->render() << endl;

     editor->saveDocument();
    return 0;
}