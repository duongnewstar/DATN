#include "appengine.h"

#include "appengine.h"
#include "screencontroller.h"
#include "appdefines.h"

AppEngine* AppEngine::m_instance = nullptr;

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_app(nullptr)
{
}

AppEngine::~AppEngine()
{
    m_app = nullptr;
}

AppEngine *AppEngine::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new AppEngine();
    }

    return m_instance;
}

void AppEngine::initialize(QApplication *app)
{
    if(!m_initialized)
    {
        m_initialized = true;
        m_app = app;

        // init app
        registerQmlObjects();
        createControllers();
        initControllers();
        initScreens();
    }
}

void AppEngine::registerQmlObjects()
{

    qmlRegisterType<AppEnums>("AppEnums", 1, 0, "AppEnums");

}

void AppEngine::createControllers()
{

    ScreenController::getInstance();
//    TranslatorController::getInstance();

//    MusicPlayerController::getInstance();
//    MusicListController::getInstance();
//    MusicBrowser::getInstance();

}

void AppEngine::initControllers()
{

    ScreenController::getInstance()->initialize(m_engine.rootContext());
//    TranslatorController::getInstance()->initialize(m_engine.rootContext());

//    MusicPlayerController::getInstance()->initialize(m_engine.rootContext());
//    MusicListController::getInstance()->initialize(m_engine.rootContext());
//    MusicBrowser::getInstance()->initialize();

}

void AppEngine::initScreens()
{

    ScreenController::getInstance()->initializeScreen(&m_engine);

}
