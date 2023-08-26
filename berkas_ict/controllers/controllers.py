# -*- coding: utf-8 -*-
# from odoo import http


# class BerkasIct(http.Controller):
#     @http.route('/berkas_ict/berkas_ict', auth='public')
#     def index(self, **kw):
#         return "Hello, world"

#     @http.route('/berkas_ict/berkas_ict/objects', auth='public')
#     def list(self, **kw):
#         return http.request.render('berkas_ict.listing', {
#             'root': '/berkas_ict/berkas_ict',
#             'objects': http.request.env['berkas_ict.berkas_ict'].search([]),
#         })

#     @http.route('/berkas_ict/berkas_ict/objects/<model("berkas_ict.berkas_ict"):obj>', auth='public')
#     def object(self, obj, **kw):
#         return http.request.render('berkas_ict.object', {
#             'object': obj
#         })
