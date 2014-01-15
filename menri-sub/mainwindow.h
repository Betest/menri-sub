#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "codeeditor.h"
#include "highlighter.h"
#include "PixmapWidget.h"
#include <QListWidget>
#include <QPushButton>
#include <QFileInfo>
#include "eventoszip.h"

QT_BEGIN_NAMESPACE
class PixmapWidget;
class EventosZip;
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
class QDockWidget;
class CodeEditor;
class QEvent;
QT_END_NAMESPACE

//![0]
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:


    MainWindow();
    //QPixmap *icon_to_be_shown;
    int posicion_ruta;
    void mandarImagen(QString  nombreImagen);
    void imagenListwidget(QString nombre);
    bool eventFilter(QObject * watched, QEvent * e);


public slots:
    void panelImagen();
    void panelEditor();
    void open();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void about();
    void obtenerTexto();
    void on_listWidget_clicked(const QModelIndex &index);

    void siguienteImagen();
    void anteriorImagen();
    void limpiar_lista();
    void RotarImagen();
    void listarScripts();

signals:
    //void	itemClicked(QListWidgetItem * item);
    //metodos a implementar
private:

    void createActions();
    void createMenus();
    void updateActions();
    //void scaleImage(double factor);
    //void adjustScrollBar(QScrollBar *scrollBar, double factor);


    QDockWidget * templateDocker;
    QDockWidget * DocArchivos;

    CodeEditor *codeEditor;
    Highlighter *highlighter;
    EventosZip *manejozip;

protected:
    virtual  void dragEnterEvent(QDragEnterEvent * event);
    virtual  void dragLeaveEvent(QDragLeaveEvent * event);
    virtual  void dragMoveEvent(QDragMoveEvent * event);
    virtual  void dropEvent(QDropEvent * event);
    void closeEvent(QCloseEvent *event);

    QAction *openAct;
    //QAction *printAct;
    QAction *exitAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *siguiente;
    QAction *anterior;
    QAction *limpiar;
    QAction *normalSizeAct;
    QAction *rotarImagen;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *imagenes;
    QAction *editor;
    QAction *herramientascript;


    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QMenu *panel;
    QMenu *herramientas;
    // QColor color;
    QScrollArea *scrollArea;
    QListWidget *view;
    PixmapWidget *pw;

    QPushButton *btnSiguiente;
    QPushButton *btnAnterior;
    QPushButton *btnLimpiar;



    float zoom;
    QList<QUrl> lista;
    QImage *qImg;

};
//![0]

#endif // MAINWINDOW_H
