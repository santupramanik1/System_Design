#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// This is an Abstract Class which resposibilities is how to render the element such as how to save images and how to save text etc;
class DocumentElement
{
public:
    virtual string render() = 0;
};

// This class is used to add text element into the doc
class TextElement : public DocumentElement
{
private:
    string text;

public:
    // constructor
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return text;
    }
};

// This class is used to add text element into the doc
class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    // Constructor
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }

    string render() override
    {
        return "[image: " + imagePath + " ]";
    }
};

// NewLineElement represents a line break in the document.
class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

// TabSpaceElement represents a tab space in the document.
class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

// Document class responsible for holding a collection of elements
class Document
{
private:
    vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    // Renders the document by concatenating the render output of all elements.
    string render()
    {
        string result;
        for (auto element : documentElements)
        {
            result += element->render();
        }
        return result;
    }
};

// Persistence abstraction
class Persistence
{
public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistence
class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << data;
            file.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// DBStorage implementation
class DbStorage : public Persistence
{
public:
    void save(string data) override
    {
        cout << "Document saved to DB" << data << endl;
    }
};

// DocumentEditor class managing client interactions
class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    // constructor
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }
    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath)
    {
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine()
    {
        document->addElement(new NewLineElement());
    }

    void addTabSpace()
    {
        document->addElement(new TabSpaceElement());
    }

    //
    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void save()
    {
        storage->save(renderDocument());
    }
};

// Client usage example
int main()
{
    Document *document = new Document();
    Persistence *persistence = new FileStorage();
    DocumentEditor *editor = new DocumentEditor(document, persistence);

    editor->addText("Hello world");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument();
    editor->save();

    return 0;
}