idf_component_register(SRCS "http_server.c" "wifi_app.c" "rgb_led.c" "main.c"
                    INCLUDE_DIRS "."
                    EMBED_FILES 
                        webpage/app.css
                        webpage/app.js
                        webpage/index.html
                        webpage/jquery-3.3.1.min.js)