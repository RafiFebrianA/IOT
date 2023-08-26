# -*- coding: utf-8 -*-

from odoo import models, fields, api


class berkas_ict(models.Model):
     _name = 'berkas_ict.berkas_ict'
     _description = 'berkas_ict.berkas_ict'

     nama = fields.Char(string="Nama")
     id = fields.Char(string='ID Tiket')
     description = fields.Text('Deskripsi')
     penyetujuan = fields.Boolean(string='Active', default=True)
#     value = fields.Integer()
#     value2 = fields.Float(compute="_value_pc", store=True)
#     description = fields.Text()
#
#     @api.depends('value')
#     def _value_pc(self):
#         for record in self:
#             record.value2 = float(record.value) / 100
