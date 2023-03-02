#include <iostream>
#include "mongoose/mongoose.h"

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    if (ev == MG_EV_HTTP_MSG)
    {
        auto hm = (struct mg_http_message *)ev_data;
        if (mg_http_match_uri(hm, "/api/sum"))
        {
            double num1, num2;
            if (mg_json_get_num(hm->body, "$[0]", &num1) && mg_json_get_num(hm->body, "$[1]", &num2))
            {
                mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{%Q:%g}\n", "result", num1 + num2);
            }
            else
            {
                mg_http_reply(c, 500, nullptr, "JSON array expected\n");
            }
        }
        else
        {
            mg_http_reply(c, 404, nullptr, "\n");
        }
    }
}

int main()
{
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);
    mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr);
    for (;;)
        mg_mgr_poll(&mgr, 10);
    mg_mgr_free(&mgr);
    return 0;
}