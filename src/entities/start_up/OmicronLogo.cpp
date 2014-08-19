#include "OmicronLogo.hpp"

namespace {

//----------------------------------CONSTANTS-----------------------------------

static const float TIMER_SPEED         = 0.015f;
static const float TEXT_ENTRANCE_SPEED = 0.1f;
static const float FLARE_EXPAND_SPEED  = 0.1f;
static const float FLARE_FADE_SPEED    = 0.012f;
static const float GLOW_SPEED          = 0.02f;
static const float CAM_DESHAKE         = 0.035f;

} // namespace anonymous

//------------------------------------------------------------------------------
//                             PUBLIC MEMBER FUNCTION
//------------------------------------------------------------------------------

void OmicronLogo::init() {

    // set up variables
    m_stage = WAIT_ONE;
    m_timer = 0.0f;

    // create the components
    initComponents();
}

void OmicronLogo::update() {

    // update based on the cinematic stage
    switch (m_stage) {

        case WAIT_ONE: {

            // update the timer
            m_timer += TIMER_SPEED * omi::fpsManager.getTimeScale();
            //move to the next stage
            if (m_timer >= 1.0f) {

                m_stage = TEXT_ENTER;
                m_timer = 0.0f;
            }
            break;
        }
        case TEXT_ENTER: {

            // move the text
            float textMove =
                TEXT_ENTRANCE_SPEED * omi::fpsManager.getTimeScale();
            m_textBottomT->translation.x -= textMove;
            m_textTopT->translation.x += textMove;
            // move to next stage
            if (m_textBottomT->translation.x <= 0.0f) {

                m_textBottomT->translation.x = 0.0f;
                m_textTopT->translation.x = 0.0f;
                m_stage = FLARE_EXPAND;
                m_camShake = 1.0f;
            } 
            break;
        }
        case FLARE_EXPAND: {

            // scale up the flare
            m_flareLongT->scale.x +=
                FLARE_EXPAND_SPEED * omi::fpsManager.getTimeScale();
            m_flareCentreT->scale +=
                FLARE_EXPAND_SPEED * omi::fpsManager.getTimeScale();
            // move to the next stage
            if (m_flareLongT->scale.x >= 1.0f) {

                m_flareLongT->scale.x   = 1.0f;
                m_flareCentreT->scale.x = 1.0f;
                m_flareCentreT->scale.y = 1.0f;
                m_flareCentreT->scale.z = 1.0f;
                m_stage = FLARE_FADE;
            }
            break;
        }
        case FLARE_FADE: {

            // fade out the flare materials
            float fadeSpeed =
                FLARE_FADE_SPEED  * omi::fpsManager.getTimeScale();
            m_flareLongMat->colour.a   -= fadeSpeed;
            m_flareCentreMat->colour.a -= fadeSpeed;
            // move to the next stage
            if (m_flareLongMat->colour.a <= 0.0f) {

                m_flareLongMat->colour.a   = 0.0f;
                m_flareCentreMat->colour.a = 0.0f;
                m_stage = GLOW;
            }
            break;
        }
        case GLOW: {

            // fade in glow and text
            float glowSpeed = GLOW_SPEED * omi::fpsManager.getTimeScale();
            m_glowMat->colour.a      += glowSpeed;
            m_poweredByMat->colour.a += glowSpeed;
            // move to next stage
            if (m_glowMat->colour.a >= 1.0f) {

                m_glowMat->colour.a      = 1.0f;
                m_poweredByMat->colour.a = 1.0f;
                m_stage = DONE;
            }
            break;
        }
    }

    // shake the camera
    if (m_camShake > 0.0f) {

        // shift the cam
        m_camT->translation.x =
            ((((rand() % 1000) / 1000.0f) * 0.025) - 0.0125) * m_camShake;
        m_camT->translation.y =
            ((((rand() % 1000) / 1000.0f) * 0.05) - 0.025) * m_camShake;
        // decrease shake
        m_camShake -= CAM_DESHAKE * omi::fpsManager.getTimeScale();
    }
    else {

        m_camT->translation.x = 0.0f;
        m_camT->translation.y = 0.0f;
    }
}

bool OmicronLogo::done() {

    return m_stage == DONE;
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void OmicronLogo::initComponents() {

    //----------------------------------CAMERA----------------------------------
    m_camT = new omi::Transform(
        "transform",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_camT->translation.z = -1.0f;
    m_components.add(
        new omi::Camera("camera", omi::cam::ORTHOGRAPHIC, m_camT));
    //-----------------------------LOGO TEXT BOTTOM-----------------------------
    m_textBottomT = new omi::Transform(
        "text_bottom_t",
        util::vec::Vector3(3.5f, 0.0f, 0.0f),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_textBottomT);
    m_components.add(omi::ResourceManager::getSprite(
        "omicron_text_bottom", "text_bottom", m_textBottomT));
    //------------------------------LOGO TEXT TOP-------------------------------
    m_textTopT = new omi::Transform(
        "text_top_t",
        util::vec::Vector3(-3.5f, 0.0f, 0.0f),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_textTopT);
    m_components.add(omi::ResourceManager::getSprite(
        "omicron_text_top", "text_top", m_textTopT));
    //-----------------------------LONG LENS FLARE------------------------------
    m_flareLongT = new omi::Transform(
        "flare_long_t",
        util::vec::Vector3(0.0f, 0.0f, 0.0f),
        util::vec::Vector3(),
        util::vec::Vector3(0.0f, 1.0f, 1.0f)
    );
    m_components.add(m_flareLongT);
    omi::Sprite* flareLongSprite = omi::ResourceManager::getSprite(
        "omicron_flare_long", "flare_long", m_flareLongT);
    m_flareLongMat = &flareLongSprite->getMaterial();
    m_components.add(flareLongSprite);
    //----------------------------CENTRE LENS FLARE-----------------------------
    m_flareCentreT = new omi::Transform(
        "flare_centre_t",
        util::vec::Vector3(0.0f, 0.0f, 0.0f),
        util::vec::Vector3(),
        util::vec::Vector3(0.0f, 0.0f, 0.0f)
    );
    m_components.add(m_flareCentreT);
    omi::Sprite* flareCentreSprite = omi::ResourceManager::getSprite(
        "omicron_flare_centre", "flare_centre", m_flareCentreT);
    m_flareCentreMat = &flareCentreSprite->getMaterial();
    m_components.add(flareCentreSprite);
    //-----------------------------------GLOW-----------------------------------
    omi::Sprite* glowSprite = omi::ResourceManager::getSprite(
        "omicron_glow", "glow", NULL);
    m_glowMat = &glowSprite->getMaterial();
    m_glowMat->colour.a = 0.0f;
    m_components.add(glowSprite);
    //-----------------------------POWERED BY TEXT------------------------------
    omi::Sprite* poweredBySprite = omi::ResourceManager::getSprite(
        "omicron_powered_by", "powered_by", NULL);
    m_poweredByMat = &poweredBySprite->getMaterial();
    m_poweredByMat->colour.a = 0.0f;
    m_components.add(poweredBySprite);

}